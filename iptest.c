#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void result(char classe)
{
    printf("Content-type: text/html\n\n");
    printf("<html lang=\"en\">\n");
    printf("<head>\n");
    printf("    <meta charset=\"UTF-8\">\n");
    printf("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    printf("    <title>Test d'adresse IP</title>\n");
    printf("    <style>\n");
    printf("        body {\n");
    printf("            font-family: Arial, sans-serif;\n");
    printf("            background-color: #f4f4f4;\n");
    printf("            display: flex;\n");
    printf("            justify-content: center;\n");
    printf("            align-items: center;\n");
    printf("            height: 100vh;\n");
    printf("            margin: 0;\n");
    printf("        }\n");
    printf("        .container {\n");
    printf("            background-color: white;\n");
    printf("            padding: 20px;\n");
    printf("            border-radius: 8px;\n");
    printf("            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);\n");
    printf("            text-align: center;\n");
    printf("            max-width: 400px;\n");
    printf("            width: 100%%;\n");
    printf("        }\n");
    printf("        h1 {\n");
    printf("            color: #333;\n");
    printf("        }\n");
    printf("        input[type=\"text\"] {\n");
    printf("            width: calc(100%% - 20px);\n");
    printf("            padding: 10px;\n");
    printf("            margin: 10px 0;\n");
    printf("            border-radius: 4px;\n");
    printf("            border: 1px solid #ccc;\n");
    printf("        }\n");
    printf("        input[type=\"submit\"] {\n");
    printf("            background-color: #4CAF50;\n");
    printf("            color: white;\n");
    printf("            padding: 10px 20px;\n");
    printf("            border: none;\n");
    printf("            border-radius: 4px;\n");
    printf("            cursor: pointer;\n");
    printf("        }\n");
    if(classe == 'I')
    {
    printf("        .invalid{\n");
    printf("            background-color: Red;\n");
    printf("            color: white;\n");
    printf("            padding: 10px 20px;\n");
    printf("            border: none;\n");
    printf("            border-radius: 4px;\n");
    printf("            box-shadow: 0 0 5px Red, 0 0 25px Red, 0 0 15px Red, 0 0 20px Red;\n");
    printf("        }\n");
    }
    if(classe != 'I')
    {
    printf("        .resultat{\n");
    if(classe =='A')
    {
        printf("            background-color: Blue;\n");
        printf("            box-shadow: 0 0 5px Blue, 0 0 25px Blue, 0 0 15px Blue, 0 0 20px Blue;\n");
    }
    if(classe =='B')
    {
        printf("            background-color: yellow;\n");
        printf("            box-shadow: 0 0 5px yellow, 0 0 25px yellow, 0 0 15px yellow, 0 0 20px yellow;\n");
    }
    if(classe =='C')
    {
        printf("            background-color: green;\n");
        printf("            box-shadow: 0 0 5px green, 0 0 25px green, 0 0 15px green, 0 0 20px green;\n");
    }
    if(classe =='D')
    {
        printf("            background-color: brown;\n");
        printf("            box-shadow: 0 0 5px brown, 0 0 25px brown, 0 0 15px brown, 0 0 20px brown;\n");
    }
    if(classe =='E')
    {
        printf("            background-color: black;\n");
        printf("            box-shadow: 0 0 5px black, 0 0 25px black, 0 0 15px black, 0 0 20px black;\n");
    }
    printf("            color: white;\n");
    printf("            padding: 10px 20px;\n");
    printf("            border: none;\n");
    printf("            border-radius: 4px;\n");
    printf("        }\n");
    }
    printf("        input[type=\"submit\"]:hover {\n");
    printf("            background-color: #45a049;\n");
    printf("        }\n");
    printf("    </style>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("    <div class=\"container\">\n");
    printf("        <h1>Tester une adresse IP</h1>\n");
    printf("        <form action=\"iptest.cgi\">\n");
    printf("            <input type=\"text\" id=\"ipInput\" name=\"IP\" placeholder=\"Reentrer votre adresse IP\" required>\n");
    printf("            <input type=\"submit\" value=\"Tester\">\n");
    if(classe == 'I')
    {
    printf("        <p class=\"invalid\">");
    printf("Adresse invalide\n");
    printf("        </p>\n");
    }
    if(classe != 'I')
    {
    printf("        <p class=\"resultat\">");
    printf("Cette Adresse est de classe %c\n",classe);
    printf("        </p>\n");
    }
    printf("        </form>\n");
    printf("        <div class=\"result\" id=\"result\">\n");
    printf("        </div>\n");
    printf("    </div>\n");
    printf("</body>\n");
    printf("</html>\n");
}
bool invalid(char *ip)
{
    int a;
    int b;
    int c;
    int d;
    sscanf(ip, "%d.%d.%d.%d", &a,&b,&c,&d);
    if(a > 256 || a < 0)
        return true;
    if(b > 256 || b < 0)
        return true;
    if(c > 256 || c < 0)
        return true;
    if(d > 256 || d < 0)
        return true;
    return false ;
}
char determine_ip_class(char *ip) {
    int first_octet;
    sscanf(ip, "%d", &first_octet);
    if(invalid(ip) == true) {
        return 'I';
    }
    if (first_octet >= 1 && first_octet <= 126) {
        return 'A';
    } else if (first_octet >= 128 && first_octet <= 191) {
        return 'B';
    } else if (first_octet >= 192 && first_octet <= 223) {
        return 'C';
    } else if (first_octet >= 224 && first_octet <= 239) {
        return 'D';
    } else if (first_octet >= 240 && first_octet <= 255) {
        return 'E';
    } 
}
void ip_test()
{
    char *query_string;
    char ip_address[16] = {0};
    query_string = getenv("QUERY_STRING");
    sscanf(query_string, "IP=%15s", ip_address);
    char classe = determine_ip_class(ip_address);
    result(classe);
}
int main() {
    ip_test();
    return 0;
}
