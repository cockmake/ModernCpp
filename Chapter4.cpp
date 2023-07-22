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
	//cout << "当前工作目录的绝对目录：" << abs_path << endl;
	//cout << "当前工作目录的相对目录：" << os::relative(abs_path) << endl;

	os::path target_path = "D:\\abc";
	//if (!os::exists(target_path)) {
	//	//os::create_directory(target_path); //create_directory可以在已有的基础上创建一层目录
	//	os::create_directories(target_path); //create_directories则可以递归创建多层目录
	//}
	//os::current_path(target_path); //current_path传入参数时会切换当前工作目录
	//os::path cur_path = os::current_path();  //不参入参数的时候则会返回当前所在的目录
	//cout << cur_path.string() << endl; 
	//
	////删除某个文件
	//os::remove(target_path / "a/a.txt");
	////删除整个文件夹
	//if(target_path != os::current_path()) os::remove_all(target_path); 
	////删除时要保证删除的target_path不是当前目录

	////遍历当前文件夹下的所有文件和文件夹，不递归遍历。
	//os::directory_iterator dir_iters(target_path);
	//for (const os::directory_entry& it : dir_iters) {
	//	cout << "路径为：" << it.path() << endl
	//		<< "类型为：" << (it.is_directory() ? "文件夹" : "文件") << endl
	//		<< "文件名为：" << it.path().filename() << endl
	//		<< "扩展名为：" << it.path().extension() << endl
	//		<< "不带扩展的文件名为：" << it.path().stem() << endl;
	//	if (!it.is_directory() && it.path().string().ends_with(".xlsx")) {
	//		//C++20中支持stirng::ends_with和starts_with
	//		cout << "\t是xlsx类型的文件" << endl
	//			<< "文件大小为：" << it.file_size() << endl; // 以B为单位
	//	}
	//	cout << string(20, '*') << endl;
	//};
	//
	////递归遍历整个文件夹下的所有子文件夹和文件
	//os::recursive_directory_iterator recursive_iters(target_path);
	//for (const os::directory_entry& blk : recursive_iters) {
	//	cout << "目录为：" << blk.path() << endl
	//		<< "类型为：" << (blk.is_directory() ? "目录" : "文件") << endl
	//		<< "占用空间：" << blk.file_size() << endl
	//		<< "最近一次的修改时间：" << os::last_write_time(blk) << endl
	//		<< string(20, '*') << endl;
	//}
	// 
	////重命名 无论是重命名还是删除都不能对当前的工作目录或工作父目录进行操作
	////b不存在a目录才能移动成功
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
