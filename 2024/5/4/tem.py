import requests
from bs4 import BeautifulSoup
import json

limit = 10
url = f'https://movie.douban.com/subject/26752088/comments?start=40&limit={limit}&status=P&sort=new_score'
headers = {'Referer':f'https://movie.douban.com/subject/26752088/comments?start=40&limit={limit}&status=P&sort=new_score',
           'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/123.0.0.0'}

response = requests.get(url,
                        headers=headers,
                        timeout=3)

if response.status_code == 200:
    soup = BeautifulSoup(response.text,'html.parser')
    hotpoint = soup.find_all(name='span',attrs={'class':'short'})
    for p in hotpoint:
        print(p.string)
else:
    print('请求失败：',response.status_code)
