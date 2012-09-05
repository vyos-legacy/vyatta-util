#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misc.h"
#include "type_check.h"

int
check_port (char *port)
{
  if (re_match(port, "^[0-9]+-[0-9]+$")) {
    if (!validateType("portrange", port, 1)) {
      printf("Error: [%s] is not a valid port range\n",port);
      return 0;
    }
    return 1;
  }
  else {
    if (!validateType("port", port, 1)) {
      printf("Error: [%s] is not a valid port\n",port);
      return 0;
    }
    return 1;
  }

}

int
check_address (char *addr)
{
  if (re_match(addr, "^[^-]+-[^-]+")) {
    if (!validateType("ipv4range", addr, 1)) {
      printf("Error: [%s] is not a valid IPv4 address range\n", addr);
      return 0;
    }
    return 1;
  }
  if (strcmp(addr, "0.0.0.0") == 0) {
    printf ("Error: zero IP address not valid in address-group");
    return 0;
  }
  if (!validateType("ipv4", addr, 1)){
    printf("Error: [%s] isn't valid IPv4 address\n", addr); 
    return 0;
  }
  return 1;
}

int
check_network (char *network)
{
  if (!validateType("ipv4net", network, 1)) {
    printf("Error: [%s] isn't a valid IPv4 network\n", network);
    return 0;
  }
  if (re_match(network, "^0.0.0.0")){
    printf("Error: zero net invalid in network-group\n");
    return 0;
  }
  return 1;
}

int 
check_member (char *type, char *member)
{
  if(strcmp(type, "port") == 0)
    return (check_port(member));
  else if (strcmp(type, "address") == 0)
    return (check_address(member));
  else if (strcmp(type, "network") == 0)
    return (check_network(member));
  else {
    printf("%s is not a valid type\n", type);
    return 1;
  }
}

int
main (int argc, char *argv[])
{
  int ret = 1;
  if (argc < 3) {
    printf("Usage: ipset-check-member <type> <port>\n");
    return 1;
  }
  char type[10];
  memset(type, 0, 10);
  strcpy(type, argv[1]);

  char member[40];
  memset(member, 0, 40);
  strcpy(member, argv[2]);
  ret = check_member(type, member);
  return (!ret);
}
