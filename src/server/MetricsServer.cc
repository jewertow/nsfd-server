#include "MetricsServer.h"
#include "Socket.h"
#include "api/MetricsRequestDeserializer.h"

MetricsServer::MetricsServer(int port, ServerSupervisor* supervisor, WatchTaskStorage* storage)
  : TcpServer(port, supervisor), task_storage(storage) {}

void MetricsServer::on_connection(int client_sock, const string &client_addr)
{
  printf("[DEBUG] MetricsServer received request from ip %s. Socket fd: %d\n", client_addr.c_str(), client_sock);

  char* raw_msg = Socket::read_raw_message(client_sock);
  auto* request = MetricsRequestDeserializer::deserialize(raw_msg);
  delete [] raw_msg;

  printf("[DEBUG] Deserialized MetricsRequest:\n%s\n", request->domain.c_str());

  process_request(client_sock, client_addr, request);
}

void MetricsServer::process_request(int client_sock, const string& client_addr, void* request)
{
  auto* metrics_req = static_cast<MetricsRequest*>(request);
  printf("[DEBUG] Processing deserialized request:\n%s\n", metrics_req->domain.c_str());

  auto* task = task_storage->get_by_domain(metrics_req->domain);
  if (task != nullptr)
  {
    fprintf(stdout, "[INFO] Task %s results as string: %s\n", task->domain().c_str(), task->results_string().c_str());
    Socket::write_and_close(client_sock, task->results_string());
  }
  else
  {
    fprintf(stdout, "[INFO] Task %s not found\n", metrics_req->domain.c_str());
    Socket::write_and_close(client_sock, "NULL");
  }

  delete metrics_req;
}