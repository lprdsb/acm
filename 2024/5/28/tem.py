import requests
from lxml import etree
from threading import Thread

class VoaThread(Thread):
    def __init__(self):
        super().__init__()
        self.links = []

    def get_links(self, page_num):
        url = f'https://www.51voa.com/VOA_Standard_{page_num}.html'
        response = requests.get(url,verify = False)
        html = etree.HTML(response.text)
        for j in range(0, 50):
            links = html.xpath(f'//*[@id="righter"]/div[3]/ul/li[{j}]/a/@href')
            #使用 XPath 表达式从 HTML 文档中提取特定位置的链接（URL）
            self.links += links
            #links是XPath表达式提取的一个链接列表，self.link+=links的意思是将links中
            #元素逐个添加到self.links这个列表中

    def run(self):
        for i in range(3, 5):
            self.get_links(i)
        print(f'prin links:{len(self.links)} and {self.links[:10]}')
        
if __name__ == '__main__':
    voa_thread = VoaThread()
    voa_thread.start()
