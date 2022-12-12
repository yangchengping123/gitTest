group_mgr_->ApplyJoinGroup(nOrgId, &gCoreGroup, &gCoreStaffIdList, &gCoreSectionIderList, &attachMsgParam, [handle](int code, Lxerror::Error* err) -> void {

		if (code != 0) {
			if (err)
			{
				AutoDispose<IGString> pStrError = err->error();
				std::string str((const char*)pStrError->ptr(), pStrError->size());

				Json::Value data;
				Json::FastWriter write;
				data["subCode"] = err->subCode();
				data["errStr"] = str;
				RESP_ERROR_CODE_DESC(handle->context_, err->code(), write.write(data).c_str());
			}
			else
			{
				RESP_ERROR_CODE(handle->context_, code);
			}
			return;
		}

		RESP_ERROR_CODEEX(handle->context_, code);
	});
