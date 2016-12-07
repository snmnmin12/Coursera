//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//struct item {
//    int x;
//    int y;
//    item(int _x, int _y) :x(_x), y(_y) {}
//};
//bool operator==(const item& ite1, const item& ite2) { return (ite1.y == ite2.y); }
//bool operator<(const item& ite1,const item& ite2) { return ite1.y > ite2.y; }
//
//void print(vector<item>& vec) {
//    vector<item>::iterator it;
//    for (it = vec.begin(); it != vec.end();it++)
//    if(it->x!=0) cout << "[ " << it->x << " " << it->y<<" ] ";
//    cout << endl;
//}
//
//
//int main()
//{
////    freopen("in1.txt", "r", stdin);
////    freopen("out.txt", "w", stdout);
//    vector<item> vec[100];
//    vector<item>::iterator it;
//    int num;
//    int i = 0;
//    cin >> num;
//    while (num--) {
//        int a, b;
//        int count=1;
//        while (cin >> a >> b)
//        {
//            if (b <0&& count==1) {count++;continue;}
//            else if(b<0 && count==2) break;
//            it = find(vec[i].begin(), vec[i].end(), item(a, b));
//            if (it == vec[i].end())
//                vec[i].push_back(item(a, b));
//            else
//                it->x += a;
//        }
//        sort(vec[i].begin(), vec[i].end());
//        print(vec[i]);
//        i++;
//    }
////    fclose(stdin);
////    fclose(stdout);
//    return 0;
//}