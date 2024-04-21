#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

vector<double> find_avg_bf(vector<double> arr, int k)
{
    int len = arr.size();
    vector<double> result;
    for (int i=0; i<len-k+1;i++)
    {
        double sum = std::accumulate(arr.begin()+i, arr.begin()+k+i, 0);
        double avg = sum/k;
        result.push_back(avg);
        
    }
    return result;
};

vector<double> find_avg(vector<double> arr, int k)
{
    int len = arr.size();
    vector<double> result;
    double sum = 0, avg = 0;
    for (int i=0; i<len-k+1; i++)
    {
        if(sum == 0)
            sum = std::accumulate(arr.begin()+i, arr.begin()+k+i, 0);
        else
        {
            sum -= arr[i-1];
            sum += arr[k+i-1];
        }
        avg = sum/k;
        result.push_back(avg);
        
    }
    return result;
};


int main()
{
    vector<double> arr({1, 3, 2, 6, -1, 4, 1, 8, 2});
    vector<double> result;
    result = find_avg(arr, 5);

    cout<<"printing result of array of size"<<result.size()<<endl;
    for(auto r : result)
    {
        std::cout << r << " ";

    }
    cout<<endl;

    return 0;
}