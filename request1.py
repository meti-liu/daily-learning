import requests

# url='https://www.google.com/search?q=周杰伦'
url = 'https://www.bing.com/search?q=周杰伦'
resp = requests.get(url)
print(resp)
print(resp.text)  # 拿到页面源代码
