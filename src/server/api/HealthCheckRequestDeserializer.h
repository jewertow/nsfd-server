#ifndef NSFD_SERVER_API_HEALTHCHECKREQUESTDESERIALIZER_H_
#define NSFD_SERVER_API_HEALTHCHECKREQUESTDESERIALIZER_H_

#include "HealthCheckRequest.h"

class HealthCheckRequestDeserializer
{
public:
  static HealthCheckRequest* deserialize(char* raw_message);
};

#endif // NSFD_SERVER_API_HEALTHCHECKREQUESTDESERIALIZER_H_
