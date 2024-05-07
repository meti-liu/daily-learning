from urllib.request import urlopen
url="http://www.google.com"
resp=urlopen(url)

with open("myweb2.html",mode="w",encoding="utf-8") as a:
    a.write(resp.read().decode("utf-8"))
print("over")