#include <iostream>
#include <map>
#include <list>


using namespace std;

struct item{
    int key,value;
    item(int k,int v){
        key = k;
        value = v;
    }
 };

list<item> itlist;
typedef list<item>::iterator list_it;
map<int,list<item>::iterator> itmap;
typedef map<int,list<item>::iterator>::iterator map_it;



class LRUCache{
    int cap,curcap;
   
public:
    LRUCache(int capacity) {
       cap = capacity; 
       curcap = 0;
       itmap.clear();
       itlist.clear();
    }
    
    int get(int key) {
        map_it it = itmap.find(key);
        if(it == itmap.end())
            return -1;
        list_it lit = it->second;
        itmap[key] = bring_front(lit);
        return lit->value;
        
    }
    
    void set(int key, int value) {
        if(itmap.find(key) != itmap.end()){
            list_it lit = itmap[key];
            (*lit).value = value;
            itmap[key] = bring_front(lit);
        }else{
            item it(key,value);
            if(curcap < cap){
                list_it nlit = itlist.insert(itlist.end(),it);
                itmap[key] = nlit;
                curcap++;
            }else{
                list_it lit = itlist.begin();
                itmap.erase(lit->key);
                itlist.pop_front();
                itmap[key] = itlist.insert(itlist.end(),it);
            }
        }
    }
    
    list_it bring_front(list_it lit){
        item it = *lit;
        itlist.erase(lit);
        list_it nlit = itlist.insert(itlist.end(),it);
        return nlit;
    } 
};

int main(){
    LRUCache cache(2);
    cout<<cache.get(2)<<endl;
    cache.set(2,6);
    cout<<cache.get(1)<<endl;
    cache.set(1,5);
    cache.set(1,2);

    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;    

    
    return 0;
}