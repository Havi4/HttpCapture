//
//  QQNetworkHeaders.c
//  QQMSFContact
//
//  Created by justinytang on 1/19/15.
//
//

#include "QQNetworkHeaders.h"

// 0 if fail, -1 if strange, 1 if all green
int qq_hostinfo_populate(struct sockaddr * sAddr, int proto_kind, void * addr) {
    sAddr->sa_family = proto_kind;
    switch (proto_kind) {
        case AF_INET:{
            struct sockaddr_in * inv4 = (struct sockaddr_in *)sAddr;
            inv4->sin_addr = *((struct in_addr *)addr);
            inv4->sin_port = htons(1337);
        }
            break;
        case AF_INET6: {
            struct sockaddr_in6 * inv4 = (struct sockaddr_in6 *)sAddr;
            inv4->sin6_addr = *((struct in6_addr *)addr);
            inv4->sin6_port = htons(1337);
        }
            break;
        default:
            return -1;
            break;
    }
    
    return 1;
}
