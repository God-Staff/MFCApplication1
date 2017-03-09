﻿#ifndef _CITY_CHINA_
#define _CITY_CHINA_

#include "datadefine.h"


const std::wstring city[31]
{
	L"上海市",L"云南省", L"内蒙古自治区",L"北京市",L"吉林省",
	L"四川省", L"天津市",L"宁夏回族自治区", L"安徽省", L"山东省",
	L"山西省",L"广东省", L"广西省", L"新疆自治区",L"江苏省",
	L"江西省",L"河北省",L"河南省",L"浙江省", L"海南省",
	L"湖北省", L"湖南省", L"甘肃省", L"福建省", L"西藏自治区",
	L"贵州省", L"辽宁省",L"重庆市",L"陕西省",L"青海省",
	L"黑龙江"
};

const int city_num[31]{
	18, 7 , 17 ,39, 12, 12, 13, 15,
	9 , 14, 14 ,12, 18, 10, 12, 18, 
	18, 14, 15 ,22, 15, 3 , 22, 10,
	17, 8 , 11 ,15, 9 , 7 , 15
};

const std::wstring city_info[31][40]
{
	{
		L"北京市",
		L"东城区",L"西城区",L"崇文区",L"宣武区",L"朝阳区",L"丰台区",L"石景山区",
		L"海淀区",L"门头沟区",L"房山区",L"通州区",L"顺义区",L"昌平区",
		L"大兴区",L"怀柔区",L"平谷区",L"密云区"
	},
	{
		L"天津市",
		L"和平区",L"河西区",L"南开区",L"河东区",L"河北区",L"红桥区"
	},
	{
		L"上海市",
		L"黄浦区" ,L"徐汇区" ,L"长宁区" ,L"静安区" ,L"普陀区" ,L"虹口区" ,L"杨浦区" ,
		L"闵行区" ,L"宝山区" ,L"嘉定区" ,L"浦东新区" ,L"金山区" ,L"松江区" ,
		L"青浦区" ,L"奉贤区" ,L"崇明区"
	},
	{
		L"重庆市",
		L"渝中区",L"大渡口区",L"江北区",L"南岸区",L"北碚区",L"渝北区",L"巴南区",
		L"长寿区",L"沙坪坝区",L"万州区",L"涪陵区",L"黔江区",L"永川区",L"合川区",
		L"江津区",L"九龙坡区",L"南川区",L"綦江区",L"大足区",L"璧山区",L"铜梁区",
		L"荣昌区",L"潼南区",L"开州区",L"梁平区",L"武隆区",L"忠县",L"城口县",
		L"垫江县",L"丰都县",L"奉节县",L"云阳县",L"巫溪县",L"巫山县",
		L"石柱土家族自治县",L"秀山土家族苗族自治县",L"酉阳土家族苗族自治县",L"彭水苗族土家族自治县"
	},
	{
		L"河北省",
		L"石家庄市",L"唐山市",L"秦皇岛市",L"邯郸市",L"邢台市",L"保定市",
		L"张家口市",L"承德市",L"沧州市",L"廊坊市",L"衡水市"
	},
	{
		L"山西省",
		L"太原市",L"大同市",L"阳泉市",L"长治市",L"晋城市",L"朔州市",L"晋中市",
		L"运城市",L"忻州市",L"临汾市",L"吕梁市"
	},
	{
		L"内蒙古自治区",
		L"呼和浩特市",L"包头市",L"乌海市",L"赤峰市",L"通辽市",L"鄂尔多斯市",L"呼伦贝尔市",
		L"巴彦淖尔市",L"乌兰察布市",L"兴安盟",L"锡林郭勒盟",L"阿拉善盟"
	},
	{
		L"辽宁省",
		L"沈阳市",L"大连市",L"鞍山市",L"抚顺市",L"本溪市",L"丹东市",L"锦州市",L"营口市",
		L"阜新市",L"阳市",L"盘锦市",L"铁岭市",L"朝阳市",L"葫芦岛市"
	},
	{
		L"吉林省",
		L"长春市",L"四平市",L"辽源市",L"通化市",L"白山市",L"松原市",
		L"白城市",L"延边朝鲜族自治州"
	},
	{
		L"黑龙江省",
		L"哈尔滨市",L"齐齐哈尔市",L"鸡西市",L"鹤岗市",L"双鸭山市",L"大庆市",L"伊春市",
		L"佳木斯市",L"七台河市",L"牡丹江市",L"河市",L"绥化市",L"大兴安岭地区"
	},
	{
		L"江苏省",
		L"南京市",L"无锡市",L"徐州市",L"常州市",L"苏州市",L"南通市",L"连云港市",L"淮安市",
		L"盐城市",L"扬州市",L"镇市",L"泰州市",L"宿迁市"
	},
	{
		L"浙江省",
		L"杭州市",L"宁波市",L"温州市",L"嘉兴市",L"湖州市",L"绍兴市",
		L"金华市",L"衢州市",L"舟山市",L"台州市",L"丽水市"
	},
	{
		L"安徽省",
		L"合肥市",L"芜湖市",L"蚌埠市",L"淮南市",L"马鞍山市",L"淮北市",L"铜陵市",
		L"庆市",L"黄山市",L"滁州市",L"阜阳市",L"宿州市",L"巢湖市",L"六市",
		L"亳州市",L"池州市",L"宣城市"
	},
	{
		L"福建省",
		L"福州市",L"厦门市",L"莆田市",L"三明市",L"泉州市",L"漳州市",
		L"南平市",L"龙岩市",L"宁德市"
	},
	{
		L"江西省",
		L"南昌市",L"景德镇市",L"萍乡市",L"九市",L"新余市",L"鹰潭市",L"赣州市",
		L"吉安市",L"宜春市",L"抚州市",L"上饶市"
	},
	{
		L"山东省",
		L"济南市",L"青岛市",L"淄博市",L"枣庄市",L"东营市",L"烟台市",
		L"潍坊市",L"济宁市",L"泰安市",L"威海市",L"日照市",L"莱芜市",
		L"临沂市",L"德州市",L"聊城市",L"滨州市",L"荷泽市"
	},
	{
		L"河南省",
		L"郑州市",L"开封市",L"洛阳市",L"平顶山市",L"安阳市",L"鹤壁市",
		L"新乡市",L"焦作市",L"濮阳市",L"许昌市",L"漯市",L"三门峡市",
		L"南阳市",L"商丘市",L"信阳市",L"周口市",L"驻马店市"
	},
	{
		L"湖北省",
		L"武汉市",L"黄石市",L"十堰市",L"宜昌市",L"襄樊市",L"鄂州市",
		L"荆门市",L"孝感市",L"荆州市",L"黄冈市",L"咸宁市",L"随州市",
		L"恩施土家族苗族自治州"
	},
	{
		L"湖南省",
		L"长沙市",L"株洲市",L"湘潭市",L"衡阳市",L"邵阳市",L"岳阳市",
		L"常德市",L"张家界市",L"益阳市",L"郴州市",L"永州市",L"怀化市",
		L"娄底市",L"湘西土家族苗族自治州"
	},
	{
		L"广东省",
		L"广州市",L"韶关市",L"深圳市",L"珠海市",L"汕头市",L"佛山市",
		L"江门市",L"湛江市",L"茂名市",L"肇庆市",L"惠州市",L"梅州市",
		L"汕尾市",L"河源市",L"阳江市",L"清远市",L"东莞市",L"中山市",
		L"潮州市",L"揭阳市",L"云浮市"
	},
	{
		L"广西壮族自治区",
		L"南宁市",L"柳州市",L"桂林市",L"梧州市",L"北海市",L"防城港市",
		L"钦州市",L"贵港市",L"玉林市",L"百色市",L"贺州市",L"河池市",
		L"来宾市",L"崇左市"
	},
	{
		L"海南省",
		L"海口市",L"三亚市"
	},
	{
		L"四川省",
		L"成都市",L"自贡市",L"攀枝花市",L"泸州市",L"德阳市",L"绵阳市",
		L"广元市",L"遂宁市",L"内江市",L"乐山市",L"南充市",L"眉山市",
		L"宜宾市",L"广安市",L"达州市",L"雅安市",L"巴中市",L"资阳市",
		L"阿坝藏族羌族自治州",L"甘孜藏族自治州",L"凉山彝族自治州"
	},
	{
		L"贵州省",
		L"贵阳市",L"六盘水市",L"遵义市",L"安顺市",L"铜仁地区",L"黔西南布依族苗族自治州",
		L"毕节地区",L"黔东南苗族侗族自治州",L"黔南布依族苗族自治州"
	},
	{
		L"云南省",
		L"昆明市",L"曲靖市",L"玉溪市",L"保山市",L"昭通市",L"丽江市",
		L"思茅市",L"临沧市",L"楚雄彝族自治州",L"红河哈尼族彝族自治州",
		L"文山壮族苗族自治州",L"西双版纳傣族自治州",L"大理白族自治州",
		L"德宏傣族景颇族自治州",L"怒江傈僳族自治州",L"迪庆藏族自治州"
	},
	{
		L"西藏自治区",
		L"拉萨市",L"昌都地区",L"山南地区",L"日喀则地区",
		L"那曲地区",L"阿里地区",L"林芝地区"
	},
	{
		L"陕西省",
		L"西安市",L"铜川市",L"宝鸡市",L"咸阳市",L"渭南市",L"延安市",
		L"汉中市",L"榆林市",L"安康市",L"商洛市"
	},
	{
		L"甘肃省",
		L"兰州市",L"嘉峪关市",L"金昌市",L"白银市",L"天水市",L"武威市",
		L"张掖市",L"平凉市",L"酒泉市",L"庆阳市",L"定西市",L"陇南市",
		L"临夏回族自治州",L"南藏族自治州"
	},
	{
		L"青海省",
		L"西宁市",L"海东地区",L"海北藏族自治州",L"黄南藏族自治州",
		L"海南藏族自治州",L"果洛藏族自治州",L"玉树藏族自治州",
		L"海西蒙古族藏族自治州"
	},
	{
		L"宁夏回族自治区",
		L"甘肃",L"银川市",L"石嘴山市",L"吴忠市",
		L"固原市",L"中卫市"
	},
	{
		L"新疆维吾尔自治区",
		L"乌鲁木齐市",L"克拉玛依市",L"吐鲁番地区",L"哈密地区",
		L"昌吉回族自治州",L"博尔塔拉蒙古自治州",L"巴音郭楞蒙古自治州",
		L"阿克苏地区",L"克孜勒苏柯尔克孜自治州",L"喀什地区",
		L"和田地区",L"伊犁哈萨克自治州",L"塔城地区",L"阿勒泰地区"
	}
};

#endif //_CITY_CHINA_