#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<filesystem>
#include<string>
using namespace std;
namespace os = filesystem;
int main4() {
	//os::path abs_path = os::absolute(os::current_path());
	//cout << "��ǰ����Ŀ¼�ľ���Ŀ¼��" << abs_path << endl;
	//cout << "��ǰ����Ŀ¼�����Ŀ¼��" << os::relative(abs_path) << endl;

	os::path target_path = "D:\\abc";
	//if (!os::exists(target_path)) {
	//	//os::create_directory(target_path); //create_directory���������еĻ����ϴ���һ��Ŀ¼
	//	os::create_directories(target_path); //create_directories����Եݹ鴴�����Ŀ¼
	//}
	//os::current_path(target_path); //current_path�������ʱ���л���ǰ����Ŀ¼
	//os::path cur_path = os::current_path();  //�����������ʱ����᷵�ص�ǰ���ڵ�Ŀ¼
	//cout << cur_path.string() << endl; 
	//
	////ɾ��ĳ���ļ�
	//os::remove(target_path / "a/a.txt");
	////ɾ�������ļ���
	//if(target_path != os::current_path()) os::remove_all(target_path); 
	////ɾ��ʱҪ��֤ɾ����target_path���ǵ�ǰĿ¼

	////������ǰ�ļ����µ������ļ����ļ��У����ݹ������
	//os::directory_iterator dir_iters(target_path);
	//for (const os::directory_entry& it : dir_iters) {
	//	cout << "·��Ϊ��" << it.path() << endl
	//		<< "����Ϊ��" << (it.is_directory() ? "�ļ���" : "�ļ�") << endl
	//		<< "�ļ���Ϊ��" << it.path().filename() << endl
	//		<< "��չ��Ϊ��" << it.path().extension() << endl
	//		<< "������չ���ļ���Ϊ��" << it.path().stem() << endl;
	//	if (!it.is_directory() && it.path().string().ends_with(".xlsx")) {
	//		//C++20��֧��stirng::ends_with��starts_with
	//		cout << "\t��xlsx���͵��ļ�" << endl
	//			<< "�ļ���СΪ��" << it.file_size() << endl; // ��BΪ��λ
	//	}
	//	cout << string(20, '*') << endl;
	//};
	//
	////�ݹ���������ļ����µ��������ļ��к��ļ�
	//os::recursive_directory_iterator recursive_iters(target_path);
	//for (const os::directory_entry& blk : recursive_iters) {
	//	cout << "Ŀ¼Ϊ��" << blk.path() << endl
	//		<< "����Ϊ��" << (blk.is_directory() ? "Ŀ¼" : "�ļ�") << endl
	//		<< "ռ�ÿռ䣺" << blk.file_size() << endl
	//		<< "���һ�ε��޸�ʱ�䣺" << os::last_write_time(blk) << endl
	//		<< string(20, '*') << endl;
	//}
	// 
	////������ ����������������ɾ�������ܶԵ�ǰ�Ĺ���Ŀ¼������Ŀ¼���в���
	////b������aĿ¼�����ƶ��ɹ�
	//os::current_path("D:/");
	//os::path a = "D:/abc", b = "D:/def";
	//b += "/" + a.filename().string();
	//try {
	//	if (a != os::current_path()) os::rename(a, b);
	//}
	//catch (exception& E) {
	//	cout << E.what() << endl;
	//}
	return 0;
}
