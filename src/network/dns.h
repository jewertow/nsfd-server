#ifndef NSFD_DNS_DNSRESOLVER_H_
#define NSFD_DNS_DNSRESOLVER_H_

#include <string>

#define AVAILABLE_PORT 0

// TODO: Funkcja powinna miec typ void i przyjmowac dodatkowo bufor na ip, bo modyfikuje juz obiekt sockaddr_in,
// TODO: więc nie powinna jednocześnie zwracać i modyfikować wartości
std::string resolve_dns(char* host_addr, struct sockaddr_in* addr_con);

std::string reverse_dns(char* ip_addr);

#endif // NSFD_DNS_DNSRESOLVER_H_
