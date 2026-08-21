123456789
My stupid boss still prefers SVN.
55555555555555555555
66666666666666666666
8888888888888888
else
{
	Json::Value root;
	CCommonFunc::makeConversationDataToJson(oid,Condata, root);
	base::UString orgDomain;
	orgDomain.Format("lx.org.%d", oid);
	root["orgDomain"] = orgDomain.ToString();
	root["oid"] = oid; 
	Json::FastWriter fastwrite;
	std::string strValue = fastwrite.write(root);
	base::UString usJson(strValue.c_str());
	vec.push_back(usJson);
}