import re

#findall 匹配字符串中所有符合正则的内容
lst = re.findall(r"\d+", "我的电话号码是10086,小明电话号码是13924671111")
print(lst)


#finditer 匹配字符串中所有的内容（返回迭代器）
it=re.finditer(r"\d+", "我的电话号码是10086,小明电话号码是13924671111")
for i in it:
    #print(i)
    print(i.group())


#search 返回的结果是match对象，拿数据要.group()
#但是只能返回第一个结果，判断有无
s=re.search(r"\d+", "我的电话号码是10086,小明电话号码是13924671111")
print(s.group())

#match 从头开始匹配，默认加了一个^
m=re.match(r"\d+", "我的电话号码是10086,小明电话号码是13924671111")
print(m.group())

#预加载正则表达式
#类似于double pi=3.1415926,就不用每一行都写出一大串数字
obj = re.compile(r"\d+")
ret = obj.finditer("我的电话号码是10086,小明电话号码是13924671111")
for it in ret:
    print(it.group())