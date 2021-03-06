#ifndef NSFD_SERVER_METRICSSERVER_H_
#define NSFD_SERVER_METRICSSERVER_H_

#include "tcp_server.h"
#include "../health/health_check_task_storage.h"

class MetricsServer : public TcpServer
{
private:
  HealthCheckTaskStorage* task_storage;

protected:
  void on_connection(int client_sock, const string& client_addr) override;

public:
  MetricsServer(int port, ServerSupervisor*, HealthCheckTaskStorage*);
  ~MetricsServer() = default;
};

#endif // NSFD_SERVER_METRICSSERVER_H_
