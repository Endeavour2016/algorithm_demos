/**
 * @date: 2018/10/20
 * @author: zlm
 * LRU 缓存的实现，使用STL里的list（双向链表）
 * 典型的实现方式：双向链表+hash表
 */

#include <list>
#include <unordered_map>
#include <cassert>
#include <iostream>
using namespace std;  

struct Element {
    int key;
    int value;
    Element(int k, int v):key(k), value(v){}
};


// 采用list，新来的数据插入到头部（头插法），这样尾部的数据是 LRU 最近最少使用的数据
class LRUCache {
private:
    list<Element> m_list;
    unordered_map<int, list<Element>::iterator> m_map;
    // unordered_map<int, list<Element>::iterator> m_map;
    //int m_capacity;
    int m_capacity;

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    // 查找指定的 key
    int get(int key) {
        if (m_map.find(key) == m_map.end()) {  // cache中没有key，直接返回
            return -1;
        } else {
            //将元素放入链表头部
            //splice(begin(), src_list&, iterator);
            m_list.splice(m_list.begin(), m_list, m_map[key]); // 把 m_list 中的 m_map[key]
            
            // 放到 m_list 中的首部，原位置中的 m_map[key] 则被删除
            m_map[key] = m_list.begin();
            return m_list.begin()->value;
        }
    }

    // 放入元素
    void put(int key, int value) {
        assert(m_capacity > 0);
        if (m_map.find(key) != m_map.end()) {
            // 如果已经存在key, 则更新 value
            m_map[key]->value = value;
            
            //将元素放入链表头部
            m_list.splice(m_list.begin(), m_list, m_map[key]);
            m_map[key] = m_list.begin();
        } else if (m_capacity == m_list.size()) {
            m_map.erase(m_list.back().key);
            m_list.pop_back();
            m_list.push_front(Element(key, value));
            m_map[key] = m_list.begin();
        } else { 
            m_list.push_front(Element(key, value));
            m_map[key] = m_list.begin();
        }
    }
};

// list成员函数splice的用法
// void splice ( iterator position, list<T,Allocator>& x, iterator i );
// 将x的元素（i）移动到目的 list 的指定位置 position，并从 x 中删除之