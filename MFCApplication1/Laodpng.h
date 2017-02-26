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
//	// ������Դ
//	HRSRC hRsrc = ::FindResource (AfxGetResourceHandle (), MAKEINTRESOURCE (nResID), lpTyp);
//	if (hRsrc == NULL) return false;
//	// ������Դ
//	HGLOBAL hImgData = ::LoadResource (AfxGetResourceHandle (), hRsrc);
//
//	if (hImgData == NULL)
//	{
//		::FreeResource (hImgData);
//		return false;
//	}
//
//	// �����ڴ��е�ָ����Դ
//	LPVOID lpVoid = ::LockResource (hImgData);
//
//	LPSTREAM pStream = NULL;
//	DWORD dwSize = ::SizeofResource (AfxGetResourceHandle (), hRsrc);
//	HGLOBAL hNew = ::GlobalAlloc (GHND, dwSize);
//	LPBYTE lpByte = (LPBYTE)::GlobalLock (hNew);
//	::memcpy (lpByte, lpVoid, dwSize);
//
//	// ����ڴ��е�ָ����Դ
//
//	::GlobalUnlock (hNew);
//	// ��ָ���ڴ洴��������
//	HRESULT ht = ::CreateStreamOnHGlobal (hNew, TRUE, &pStream);
//	if (ht != S_OK)
//	{
//		GlobalFree (hNew);
//	}
//	else {
//		// ����ͼƬ
//		pImage->Load (pStream);
//		GlobalFree (hNew);
//	}
//
//	// �ͷ���Դ
//	::FreeResource (hImgData);
//	return true;
//}
////��CImage��������һ������CImage::LoadFromResource, ������ʵ�����ǵ��õ���LoadImage�������, ��ȫ��û�õ�.�������ϵĴ���, Ȼ��Ϳ���д�߼�������:LoadImageFromResource (&m_ImaBg, IDB_BG, _T ("RCPNG"));
//
//#endif //End __LOAD_PNG_BG__


//
//
//HICON   myIcon[3];
//myIcon[0] = AfxGetApp ()->LoadIcon (IDI_ICON1);//ע��������ͨ��LoadIcon���HICON   
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
//ֻҪ�ܻ�þ�����ܻ��ID
//----------------------
//�����Ѿ���������ʾͼ���� ������仰������
//((CListCtrl *)lParam)->InsertItem (i, m_strTitle, i);