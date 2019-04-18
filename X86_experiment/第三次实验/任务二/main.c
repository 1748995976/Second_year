#include <stdio.h>
#include <mem.h>
#pragma inline
void menu(int AUTH);

typedef struct{
    char ag[10];
    char bg;
    unsigned short cg[5];
}Good;

extern void WAN2(void);
extern void WAN3(void);
extern void WAN4(void);
extern void WAN5(void);
extern Good GA1[3];

int main() {
    char *BNAME = "ZHANCHENG";
    char *BPASS = "test";
    char *LEAVES = "--*--*--*--*--*--*--*--*--*--*";
    char *SNAME = "SHOP";
    char *REMIND1 = "Please input your account number!";
    char *REMIND2 = "Please input your password!";
    char *REINPUT = "The account number or password is not right.Please try again!";
    int AUTH = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    char ch;
    unsigned short suggest = 0;
    char inname[20];
    char name[15];
    char pass[10];
    printf("%s\n%s", SNAME, LEAVES);
    while(1) {
        //判断输入的账号和密码
        while (1) {
            printf("\n%s\n", REMIND1);
            for (a = 0; a < 15; a++) {
                name[a] = getchar();
                if (name[a] == '\n') {
                    name[a] = '\0';
                    break;
                }
            }
            printf("%s\n", REMIND2);
            for (a = 0; a < 10; a++) {
                pass[a] = getchar();
                if (pass[a] == '\n') {
                    pass[a] = '\0';
                    break;
                }
            }
            if (name[0] == '\0') {
                AUTH = 0;
                printf("Welcome customer!\n");
                break;
            } else if (name[0] == 'q' && name[1] == '\0') {
                return 0;
            } else if (!strcmp(BNAME, name) && !strcmp(BPASS, pass)) {
                AUTH = 1;
                printf("Welcome boss!\n");
                break;
            } else {
                printf("%s\n", REINPUT);
            }
        }
        //判断结束
        //功能选择
        while(1){
            printf("%s\n", LEAVES);
            menu(AUTH);
            printf("%s\n", LEAVES);
            printf("Please choose your choice!\n");
            ch = getchar();
			if(ch == '\n')
				break;
            getchar();//接受回车
            if(ch - '1' < 0 || ch - '6' > 0)
                break;
            else if(AUTH == 0 && ch != '1' && ch != '6')
                continue;
            else{
                switch (ch){
                    case '1':{
                        printf("Please input the name of commodity!\n");
						while(1){
							c = 0;
							for (a = 0; a < 20; a++) {
								inname[a] = getchar();
								if (inname[a] == '\n') {
									inname[a] = '\0';
									break;
								}
							}
							if(inname[0] == '\0')
                            break;
							else{
								for(a = 0;a < 3;a++){
									for(b = 0;b < 10;b++){
										if(GA1[a].ag[b] != inname[b])
											break;
										else if(GA1[a].ag[b] == inname[b] && GA1[a].ag[b+1] == 0 && inname[b+1] == '\0'){
											c = 1;
											break;
										}
									}
									if(c == 1)
										break;
								}
								if(c == 1){
									printf("%s\n%s\n",inname,LEAVES);
									suggest = (unsigned short)((GA1[a].cg[0]*1280)/(GA1[a].cg[1]*GA1[a].bg))
											+ (unsigned short)((GA1[a].cg[3]*128)/GA1[a].cg[2]);
									printf("DISCOUNT:%hu\n",GA1[a].bg);
									printf("COST PRICE:%hu\n",GA1[a].cg[0]);
									printf("MARKING PRICE:%hu\n",GA1[a].cg[1]);
									printf("COST AMOUNT:%hu\n",GA1[a].cg[2]);
									printf("MARKING PRICE:%hu\n",GA1[a].cg[3]);
									printf("SUGGEST:%hu\n",suggest);
									printf("%s\n",LEAVES);
									break;
								}else{
									printf("There is not this commodity!Please try again!\n");
									continue;
								}
							}
						}
						break;
                    }
                    case '2':{
                        WAN2();
                        break;
                    }
                    case '3':{
                        WAN3();
                        break;
                    }
                    case '4':{
                        WAN4();
                        break;
                    }
                    case '5':{
                        WAN5();
                        break;
                    }
                    case '6':{
                        return 0;
                    }
                }
            }
        }
    }
}

void menu(int AUTH){
    char *SFCI = "1.Search for commodity information";
    char *MCI = "2.Modifying commodity information";
    char *CTEDOC = "3.Compute the recommendation degree of commodity";
    char *RANKME = "4.Compute the rank of commodity";
    char *OACI = "5.Output all commodity information";
    char *ESYSTEM = "6.Exit system";
    printf("%s\n",SFCI);
    if(AUTH == 1){
        printf("%s\n",MCI);
        printf("%s\n",CTEDOC);
        printf("%s\n",RANKME);
        printf("%s\n",OACI);
    }
    printf("%s\n",ESYSTEM);
}