#include <windows.h>
#include <string>
#include <iostream>

void users(std::wstring& login, std::wstring& senha) {

    std::wstring usuarios[][2] = 
    {
        {L"Joaquim", L"jqm"},
        {L"Vasconcelos", L"saojanu"},
        {L"Cristóvão", L"cruzdemalta"},
        {L"Alessander", L"cartorio"},
        {L"Gil", L"azeitona"},
    };

    login = usuarios[0][0];
    senha = usuarios[0][1];
}

// Função de callback da janela
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hwndUsername, hwndPassword, hwndLoginButton;

    switch (uMsg) {
        case WM_CREATE: {
            // Criar os controles da janela
            CreateWindowW(L"Static", L"Usuário:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hwnd, NULL, NULL, NULL);
            hwndUsername = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hwnd, NULL, NULL, NULL);

            CreateWindowW(L"Static", L"Senha:", WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, hwnd, NULL, NULL, NULL);
            hwndPassword = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 100, 150, 25, hwnd, NULL, NULL, NULL);

            hwndLoginButton = CreateWindowW(L"Button", L"Login", WS_VISIBLE | WS_CHILD, 150, 150, 100, 30, hwnd, (HMENU)1, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            if (HIWORD(wParam) == BN_CLICKED) {
                // Obter o identificador do controle que disparou o evento
                int controlId = LOWORD(wParam);

                // Verificar se o botão de login foi clicado
                if (controlId == 1) {
                    // Obter os valores do usuário e senha
                    const int BUFFER_SIZE = 256;
                    wchar_t username[BUFFER_SIZE];
                    wchar_t password[BUFFER_SIZE];
                    GetWindowTextW(hwndUsername, username, BUFFER_SIZE);
                    GetWindowTextW(hwndPassword, password, BUFFER_SIZE);

                    // Comparar com as credenciais válidas
                    std::wstring usernameStr(username);
                    std::wstring passwordStr(password);

                    std::wstring login;
                    std::wstring senha;

                    users(login, senha);

                    if (usernameStr == login && passwordStr == senha) {
                        std::wstring welcomeMessage = L"Bem-vindo, " + usernameStr + L"!";
                        MessageBoxW(hwnd, welcomeMessage.c_str(), L"Login bem-sucedido", MB_OK);
                    } else {
                        MessageBoxW(hwnd, L"Credenciais inválidas. Tente novamente.", L"Erro de login", MB_OK | MB_ICONERROR);
                    }
                }
            }
            break;
        }
        case WM_DESTROY: {
            // Encerrar o programa ao fechar a janela
            PostQuitMessage(0);
            return 0;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Registrar a classe da janela
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"LoginWindow";
    RegisterClassW(&wc);

    // Criar a janela
    HWND hwnd = CreateWindowW(L"LoginWindow", L"Tela de Login", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 250, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);

    // Loop de mensagem
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
