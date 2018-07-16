
python3实现火车票查询工具

1通过谷歌的调试器,得到12306查询命令的接
2安装requests ,docopt,re,stations
	使用docopt库,解析输入信息 Usage: ticket [-dgktz] <from> <to> <date>
	得到字典,保存数据
	将数据添充到url中.
	verify = False	验证证书 NO
