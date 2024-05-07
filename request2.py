import requests

url = "https://fanyi.baidu.com/sug"

s = input("请输入你要翻译的英文单词")
dat = {"kw": s}
# 发送post请求，发送的数据放在字典中，动过data来传递数据
resp = requests.post(url, data=dat)
print(resp.json())  # 将服务器返回内容直接处理成json，也就是字典dict
