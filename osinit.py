from phonenumbers import carrier,timezone,geocoder
from bs4 import BeautifulSoup
import phonenumbers
import requests
import json
import os


os.system("clear")


def findGeolocation(target_ip):
	os.system("clear")
	url = f"http://ip-api.com/json/{target_ip}"
	print(f"target > {url}")
	site = requests.get(url)		
	result = json.loads(site.text)
	

	for i in result:
		print(f"{i} : {result[i]}")


def findLocaitonWithNumber(number):
	os.system("clear")
	if number.startswith("+90"):
	    print("Numara Doğru!")
	    Numara = phonenumbers.parse(number)
	    zaman = timezone.time_zones_for_number(Numara)
	    sim_adi = carrier.name_for_number(Numara, "tr")
	    bolge = geocoder.description_for_number(Numara, "tr")

	    print("Saat Dilimi :", zaman)
	    print("Sim adı:", sim_adi)
	    print("Yaşadığı Ülke(bölge) :", bolge)
	else:
	    print("+90 Giriniz.")


def checkURL(target_url):
	os.system("clear")
	url = f"https://iplogger.org/url-checker/?url={target_url}"
	print(f"target > {url}")		
	html = requests.get(url).content		
	soup = BeautifulSoup(html,"html.parser")	#soup objesi oluştur.
	result = soup.find("div", attrs={"class":"server-info"}).text
	print(result)

def maskUrl():
	os.system("clear && git clone https://github.com/jaykali/maskphish.git && cd maskphish && chmod 777 maskphish.sh && bash maskphish.sh")

def camPhishing():
	os.system("clear && apt-get -y install php openssh git wget && git clone https://github.com/techchipnet/CamPhish.git && cd CamPhish && chmod 777 camphish.sh && bash camphish.sh")

def findUsername():
	os.system("clear && git clone https://github.com/sherlock-project/sherlock.git && cd sherlock && python3 -m pip install -r requirements.txt && python3 sherlock --help")

def getInfoForWeb(domain):
	os.system(f"whois {domain}")
	os.system(f"nslookup -type=A {domain}")
	os.system(f"nslookup -type=MX {domain} 1.1.1.1")
	os.system(f"nslookup -type=TXT {domain}")
	os.system(f"dig {domain} A")
	os.system(f"dig {domain} TXT")
	os.system(f"curl {domain}/sitemap.xml")
	os.system(f"curl {domain} -v")


print("""

	[1] find location with ip
	[2] find location with phone number
	[3] mask url
	[4] check url
	[5] Webcam phising
	[6] find username
	[7] create fake social media platforms chat message
	[8] Active/Passive info

	""")

choose_ans = input("Please select an option: ")
if choose_ans == "1":
	target_ip = input("Enter target ip address: ")
	findGeolocation(target_ip)
elif choose_ans == "2":
	number = input("Telefon Numarasını ( + kullanarak ) Gir: ")
	findLocaitonWithNumber(number)
elif choose_ans == "3":
	maskUrl()
elif choose_ans == "4":
	target_ip = input("Enter target url: ")
	checkURL(target_ip)
elif choose_ans == "5":
	camPhishing()
elif choose_ans == "6":
	findUsername()
	print("python3 sherlock <username>")
elif choose_ans == "7":
	print("""

		Fake wp chat message   -> https://fakeinfo.net/fake-whatsapp-chat-generator
		Fake meta chat message -> https://fakeinfo.net/fake-facebook-chat-generator
		Fake ig chat message   -> https://fakeinfo.net/fake-instagram-dm-generator
		Fake tw chat message   -> https://fakeinfo.net/fake-twitter-chat-generator
		Fake tk profile        -> https://fakeinfo.net/fake-tiktok-profile-generator
		Fake android message   -> https://fakeinfo.net/fake-android-text-message-generator
		Fake iphone message    -> https://fakeinfo.net/fake-iphone-text-message-generator
		""")

elif choose_ans == "8":
	domain = input("Enter domain: ")
	getInfoForWeb(domain)