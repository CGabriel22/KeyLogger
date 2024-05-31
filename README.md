## Keylogger

Um keylogger é um tipo de malware que captura as teclas digitadas em uma maquina infectada, salvando e posteriormente enviando para o atacante. Com isso esse malware consegue facilmente espionar e descobrir informações sensíveis como senhas e dados financeiros. Daí o grande perigo desse tipo de malware e a necessidade de estuda-lo para o combater.

A keylogger is a type of malware that captures keystrokes made on an infected machine, saving them and later sending them to the attacker. This malware can easily spy on and discover sensitive information such as passwords and financial data. Hence the great danger of this type of malware and the need to study it to combat it.

---

#### SO: Windows 10/11

## Cloning this repository
```bash
git clone https://github.com/CGabriel22/KeyLogger

cd KeyLogger/
```

## Getting Started
Execute o "keylogger.exe" em uma maquina, imediatamente ele começa a capturar as teclas do usuário e grava no caminho "D:\\keylogger.txt" conforme configurado na linha 20 do código.

OBS: O keylogger não tem nenhuma técnica de ofuscação ou de evasão de antivirus, então só será possível executa-lo com antivirus desativado.

OBS2: O keylogger tem uma função denominada "autorun()" para permanência na maquina infectada, onde o malware é colocado no diretório de inicialização: "APPDATA\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\". Desse modo sempre que a maquina é reiniciada o programa será autoexecutado novamente mesmo que tenha sido interrompido.

Run "keylogger.exe" on a machine, it immediately starts capturing the user's keystrokes and writes to the path "D:\\keylogger.txt" as configured in line 20 of the code.

NOTE: The keylogger does not have any obfuscation or antivirus evasion techniques, so it will only be possible to run it with antivirus deactivated.

NOTE2: The keylogger has a function called "autorun()" to remain on the infected machine, where the malware is placed in the startup directory: "APPDATA\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\" . This way, whenever the machine is restarted, the program will auto-execute again even if it has been interrupted.

## Melhorias futuras
[] Evasão de antivirus
[] Ofuscação baseado em criptografia
[] Envio do arquivo "keylogger.txt" para um email anônimo 
