//#ifndef __LOAD_PNG_BG__
//#define  __LOAD_PNG_BG__
//class LoadImageFromResource:C
//{
//public:
//	LoadImageFromResource ();
//	~LoadImageFromResource ();
//
//private:
//
//};
//
//LoadImageFromResource::LoadImageFromResource ()
//{
//}
//
//LoadImageFromResource::~LoadImageFromResource ()
//{
//}
//static bool LoadImageFromResource (IN CImage* pImage,
//	IN UINT nResID,
//	IN LPCSTR lpTyp)
//{
//	if (pImage == NULL) return false;
//	pImage->Destroy ();
//	// 查找资源
//	HRSRC hRsrc = ::FindResource (AfxGetResourceHandle (), MAKEINTRESOURCE (nResID), lpTyp);
//	if (hRsrc == NULL) return false;
//	// 加载资源
//	HGLOBAL hImgData = ::LoadResource (AfxGetResourceHandle (), hRsrc);
//
//	if (hImgData == NULL)
//	{
//		::FreeResource (hImgData);
//		return false;
//	}
//
//	// 锁定内存中的指定资源
//	LPVOID lpVoid = ::LockResource (hImgData);
//
//	LPSTREAM pStream = NULL;
//	DWORD dwSize = ::SizeofResource (AfxGetResourceHandle (), hRsrc);
//	HGLOBAL hNew = ::GlobalAlloc (GHND, dwSize);
//	LPBYTE lpByte = (LPBYTE)::GlobalLock (hNew);
//	::memcpy (lpByte, lpVoid, dwSize);
//
//	// 解除内存中的指定资源
//
//	::GlobalUnlock (hNew);
//	// 从指定内存创建流对象
//	HRESULT ht = ::CreateStreamOnHGlobal (hNew, TRUE, &pStream);
//	if (ht != S_OK)
//	{
//		GlobalFree (hNew);
//	}
//	else {
//		// 加载图片
//		pImage->Load (pStream);
//		GlobalFree (hNew);
//	}
//
//	// 释放资源
//	::FreeResource (hImgData);
//	return true;
//}
////在CImage类里面有一个方法CImage::LoadFromResource, 可是它实际上是调用到了LoadImage这个方法, 完全是没用滴.有了以上的代码, 然后就可以写逻辑代码了:LoadImageFromResource (&m_ImaBg, IDB_BG, _T ("RCPNG"));
//
//#endif //End __LOAD_PNG_BG__


//
//
//HICON   myIcon[3];
//myIcon[0] = AfxGetApp ()->LoadIcon (IDI_ICON1);//注意这里是通过LoadIcon获得HICON   
//myIcon[1] = AfxGetApp ()->LoadIcon (IDI_ICON2);
//myIcon[2] = AfxGetApp ()->LoadIcon (IDR_MAINFRAME);
//myList.Create (32, 32, ILC_COLOR32, 8, 8);
//for (int i = 0; i < 3; i++)
//{
//	myList.Add (myIcon[i]);
//}
//m_friend_list.SetImageList (&myList, LVSIL_SMALL);
//for (i = 0; i < 3; i++)
//{
//	LVITEM lvitem;
//	lvitem.mask = LVIF_IMAGE | LVIF_TEXT;
//	lvitem.iItem = i;
//	lvitem.pszText = "        ";
//	lvitem.iImage = i;
//	lvitem.iSubItem = 0;
//	m_friend_list.InsertItem (&lvitem);
//}
//----------------------
//只要能获得句柄就能获得ID
//----------------------
//现在已经能正常显示图标了 改了这句话就行了
//((CListCtrl *)lParam)->InsertItem (i, m_strTitle, i);