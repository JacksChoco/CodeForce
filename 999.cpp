//
//  main.cpp
//  codeforce
//
//  Created by Jack on 2018. 6. 25..
//  Copyright © 2018년 Jack. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#define MAX(a,b) a > b ? a : b
#define MAXIMUM 100001

using namespace std;

vector < vector <int>> cache;

int maxFavorite(int people, int total, vector <int> fav){
    if(people == 0 || total <= 0){
        return 0;
    }
    
    if( cache[people][total] != -1){
        return cache[people][total];
    }
    
    int maxCard = fav.size();
    
    int temp = 0;
    
    for(int i = maxCard - 1; i >= 0; i--){
        if(total - i >= 0){
            int current = fav[i] + maxFavorite( people - 1, total - i, fav);
            temp = MAX(temp, current);
        }
    }
    
    cache[people][total] = temp;
    
    return temp;
}

int main(int argc, const char * argv[]) {
    int N,K;
    vector <int> cards;
    vector <int> my_fav;
    vector <int> fav_score;
    
    cards.resize(MAXIMUM,0);
    my_fav.resize(MAXIMUM,0);
    
    cin >> N >> K;
    
    cache.clear();
    cache.resize(N+1);
    
    for(int i=0; i < N + 1; i ++){
        vector<int> cache_total;
        cache_total.resize(N*K+1, -1);
        cache[i] = cache_total;
    }
    
    for(int i = 0; i < N*K; i++){
        int a;
        cin >> a;
        cards[a]++;
    }

    for(int i= 0; i <N; i++){
        int a;
        cin >> a;
        my_fav[a]++;
    }

    fav_score.resize(K+1);
    fav_score[0] = 0;
    for(int i= 1; i <K + 1; i++){
        cin >> fav_score[i];
    }
    
    int max = 0;
    
    for(int i =1; i < MAXIMUM; i++ ){
        max += maxFavorite( my_fav[i] ,cards[i], fav_score);
    }
    
    // insert code here...
    cout << max;
    return 0;
}
