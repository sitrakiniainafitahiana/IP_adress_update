#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DATA_OUTPUT();
void registration(int *number, int *number2, int *number3, int *number4);


int main(){
    DATA_OUTPUT();
}


void DATA_OUTPUT(){
    char *data=NULL;
    data=getenv("QUERY_STRING");
    int i=5,
        count=0,    
        number1=0,
        number2=0,
        number3=0,
        number4=0;

    while(data[i]!='\0'){
        if (data[i]>='a' && data[i]<='z'||data[i]>='A' && data[i]<='Z'){
            count=1;
        }
        i++;
    }
    if(i>20||count==1){ 
        printf("content-type: text/html\n\n");
        printf("    <!DOCTYPE HTML>");
        printf("    <HTML>");
        printf("    <LINK rel=\"stylesheet\" href=\"fond.css\"/>");
        printf("    <LINK rel=\"stylesheet\" href=\"Style.css\"/>");
        printf("        <FORM ACTION=\"id.cgi\" METHOD=\"get\">");
        printf("        Invalid IP. Please try again</BR>");
        printf("        <LABEL FOR=\"Data\">IP:</LABEL>");
        printf("        <INPUT TYPE=\"text\" NAME=\"Data\" PLACEHOLDER=\"E.g: xxx.xxx.xxx.xxx\" required></P>");        
        printf("        <INPUT TYPE=\"SUBMIT\" VALUE=\"Send\">");        
        printf("        </FORM></BR>");    
        printf("        </BODY>");
        printf("    </HTML>");    
    }else{
        sscanf(data, "Data=%d.%d.%d.%d", &number1, &number2, &number3, &number4);
        registration(&number1, &number2, &number3, &number4);
    }
}

void registration(int *number1, int *number2, int *number3, int *number4){
    int Not_IP=256;

    printf ("content-type: text/html\n\n"); 
    printf("<!DOCTYPE HTML>\n");
    printf("<HTML>");
    printf("    <LINK rel=\"stylesheet\" href=\"fond.css\"/>");
    printf("    <LINK rel=\"stylesheet\" href=\"Style.css\"/>");
    printf("    <BODY>");
    printf("        %d.%d.%d.%d</BR>", *number1, *number2, *number3, *number4);
    printf("    </BODY>");
    printf("</HTML>");

    if (*number1 >= Not_IP||*number1 < 0||*number2 >= Not_IP||*number2 < 0||*number3 >= Not_IP||*number3 < 0||*number4 >= Not_IP||*number4 < 0){ 
        printf("<!DOCTYPE HTML>\n");
        printf("<HTML>");
        printf("    <LINK rel=\"stylesheet\" href=\"fond.css\"/>");
        printf("    <LINK rel=\"stylesheet\" href=\"Style.css\"/>");
        printf("    <BODY>");
        printf("        <B>invalid IP adress</B></BR>");
        printf("    </BODY>");
        printf("</HTML>");
    }
    else{
        printf("<!DOCTYPE HTML>\n");
        printf("<HTML>");
        printf("    <LINK rel=\"stylesheet\" href=\"fond.css\"/>");
        printf("    <LINK rel=\"stylesheet\" href=\"Style.css\"/>");
        printf("    <BODY>");
        printf("        <B>valid IP adress</B></BR>");

        if (*number1>=0 && *number1<=127){
            printf("        IPv4: A Class</BR>");
        }
        else if(*number1>127 && *number1<=191){
            printf("        IPv4: B Class</BR>");
        }
        else if(*number1>191 && *number1<=223){
            printf("        IPv4: C Class</BR>");
        }
        else if(*number1>223 && *number1<=239){
            printf("        IPv4: D Class</BR>");
        }
        else if(*number1>239 && *number1<=255){
            printf("        IPv4: E Class</BR>");
        }
        printf("    </BODY>");
        printf("</HTML>");
    }
}
