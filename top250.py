# 拿到页面源代码 request
# 通过re拿到有效信息 re
import requests
import re
import csv

url = "https://movie.douban.com/top250"
headers ={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/124.0.0.0 Safari/537.36 Edg/124.0.0.0"}
resp =requests.get(url,headers=headers)
page_content = resp.text
# re.S保证.可以匹配换行符
obj = re.compile(r'<li>.*?<span class="title">(?P<name>.*?)</span>.*?'
                 r'<p class="">.*?<br>(?P<year>.*?)&nbsp.*?'
                 r'average">(?P<score>.*?)</span>.*?'
                 r'<span>(?P<num_of_people>.*?)人评价',re.S)
result = obj.finditer(page_content)
f = open("data.csv" , mode="w",encoding="utf-8")
csvwriter = csv.writer(f)
for i in result:
    # print(i.group("name"))
    # print(i.group("year").strip()) # strip可以过滤空格和换行
    # print(i.group("score"))
    # print(i.group("num_of_people"))
    dic = i.groupdict()
    dic['year']=dic['year'].strip()
    csvwriter.writerow(dic.values())
f.close()
print("over")