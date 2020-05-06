#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>

int main()
{

    int i, x;
    char str[]="E;5:HEH885<8";

    for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3;


    int fd;
    struct ifreq ifr;
    char *iface = "eth0";
    unsigned char *m = NULL;

    memset(&ifr, 0, sizeof(ifr));

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name , iface , IFNAMSIZ-1);

    if (0 == ioctl(fd, SIOCGIFHWADDR, &ifr)) {
        m = (unsigned char *)ifr.ifr_hwaddr.sa_data;

        char mstr[]="";
        sprintf(mstr, "%.2X%.2X%.2X%.2X%.2X%.2X" , m[0], m[1], m[2], m[3], m[4], m[5]);

        if(strcmp(mstr, str)==0)
        {
                printf("Access granted.\n");

                char p[]="vxshusdvvzrug";
                for(i = 0; (i < 100 && p[i] != '\0'); i++)
                        p[i] = p[i] - 3;
                char command[]="echo -n ";
                strcat(command, p);
                strcat(command, " | cryptsetup luksOpen ./vault.img vault -d -");
                system(command);
                system("mkdir /tmp/vault");
                system("mount /dev/mapper/vault /tmp/vault");
                system("sh /tmp/vault/vault.sh");
                system("umount /tmp/vault && rm -rf /tmp/vault");
                system("umount /dev/mapper/vault");
                system("cryptsetup luksClose vault");
        }else{
                printf("Access denied.\n");
        }
    }

    close(fd);

    return 0;
}