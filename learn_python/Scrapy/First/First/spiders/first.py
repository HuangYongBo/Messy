# -*- coding: utf-8 -*-
import scrapy


class FirstSpider(scrapy.Spider):
    name = 'first'
    allowed_domains = ['www.itcast.cn']
    start_urls = ['http://www.itcast.cn/']

    def parse(self, response):
	print(response.body)
       # pass
