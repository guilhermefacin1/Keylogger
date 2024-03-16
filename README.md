# Keylogger em C

Este é um programa simples de keylogger desenvolvido em C para o ambiente Windows. O programa registra as teclas pressionadas pelo usuário e exibe os caracteres correspondentes no console. É importante observar que o uso deste software pode ter implicações legais e éticas. Certifique-se de entender e cumprir todas as leis e regulamentos aplicáveis ao usar este software.
Funções Utilizadas.
A realização desse programa aconteceu, para que entendesse o funcionamento de um Software Malicioso em execução.

O programa utiliza as seguintes funções da API do Windows:

    SetWindowsHookEx(): Esta função é usada para estabelecer um hook de procedimento de aplicativo, permitindo que o programa monitore eventos do sistema, como pressionamento de teclas.
    UnhookWindowsHookEx(): Remove um hook de procedimento de aplicativo instalado em um hook de cadeia de procedimentos.
    CallNextHookEx(): Passa a mensagem para o próximo hook na cadeia de hooks, permitindo que outros aplicativos também recebam e processem o evento.

Para mais informações sobre essas funções, consulte a [documentação oficial da Microsoft](https://learn.microsoft.com/en-us/windows/win32/api/winuser).
Compilação e Execução

Para compilar o programa, é necessário um compilador C compatível com o ambiente Windows, como o MinGW. Abaixo está um exemplo de como compilar o programa usando o GCC:

bash

gcc keylogger.c -o keylogger.exe -luser32

Após compilar, execute o programa keylogger.exe.
Aviso Legal

Este programa é fornecido apenas para fins educacionais e de teste. É crucial respeitar a privacidade e os direitos dos outros. O uso de keyloggers pode ser ilegal e violar a privacidade das pessoas. Certifique-se de entender e obedecer às leis e regulamentos locais ao usar este software.

