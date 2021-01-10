#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


bool cmp_list(const pair<int,int>& a, const pair<int,int> &b ){
    if(a.second==b.second) 
        return a.first < b.first;
    else 
        return a.second > b.second;
}

bool cmp_cnt(const pair<string,int> &a, const pair<string,int> &b){
        return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int,int>>> genreAndPlaylist;
    unordered_map<string, int> genreAndCnt;
    vector<pair<string, int>> genreAndCnt_v;

    /*hash map에 데이터 삽입*/
    for(int i=0;i<plays.size();i++){
        genreAndPlaylist[genres[i]].push_back({i, plays[i]});
        genreAndCnt[genres[i]]+=plays[i];
    }

    /*장르별 재생음악들 빈도수를 내림차순으로 정렬*/
    for(auto &genre: genreAndPlaylist)
        sort(genre.second.begin(), genre.second.end(), cmp_list);
    
    /*장르별 총 재생횟수 내림차순으로 정렬*/
    genreAndCnt_v.assign(genreAndCnt.begin(), genreAndCnt.end());
    sort(genreAndCnt_v.begin(), genreAndCnt_v.end(), cmp_cnt);

    for(int i=0;i<genreAndCnt_v.size();i++){
        string genre = genreAndCnt_v[i].first;

        /*음악이 1개면 1개만, 2개이상이면 2개까지만 answer에 저장*/
        for(int j=0; j<genreAndPlaylist[genre].size() &&(j<2);j++){
            answer.push_back(genreAndPlaylist[genre][j].first);
        }
    }
    return answer;
}