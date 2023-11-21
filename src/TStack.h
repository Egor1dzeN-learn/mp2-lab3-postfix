//
// Created by egorm on 25.10.2023.
//

#ifndef UNTITLED7_TSTACK_H
#define UNTITLED7_TSTACK_H

#include <iostream>


template<typename T>
class TStack {
private:
    T *begin;
    T *end;
    int size;
public:
    TStack(){
        size = 100;
        begin = new T[size];
        end = begin;
    }
    TStack(T _n){

        if(_n>=0){
            size = _n;
            begin = new T[size];
            end = begin;
        }else{
            throw std::invalid_argument("Invalid Argument");
        }
    }
    TStack(const TStack& s){
        size = s.size;
        begin = new T[size];
        for(int i =0;i<(s.end-s.begin);++i){
            begin[i] = s.begin[i];
        }
        end = begin + (s.end - s.begin);
    }
    ~TStack(){
        delete[] begin;
    }
    void push(T el){
        int now_size = (end - begin);
        //std::cout<<now_size<<size<<std::endl;
        if(now_size >= size){
            T* tmp = new T[size*2];

            for(int i = 0;i<size;++i){
                tmp[i] = begin[i];
            }
            delete[] begin;
            begin = tmp;
            end = begin +size;
            *end = el;
            //std::cout<<"!!!"<<begin[size]<<std::endl;
//            std::cout<<*end<<std::endl;

            size = size*2;
            //std::cout<<size<<std::endl;
        }else{
            *end = el;
//            std::cout<<*end<<std::endl;


        }
        end++;
    }
    T top(){
        if(!isEmpty()){
            return *(end-1);
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }
    void getall(){
        for(int i =0;i<(end - begin);++i){
            std::cout<<begin[i]<<std::endl;
        }
    }
    T pop(){
        end--;
        return *end;
    }
    int getSize(){
        return (end-begin);
    }
    bool isEmpty(){
        return begin == end;
    }
    bool operator==(const TStack& s){
        if((s.end - s.begin) != (end - begin)){
            return false;
        }
        for(int i =0;i<end-begin;++i){
            if(begin[i] !=  s.begin[i]){
                return false;
            }
        }
        return true;
    }
    friend std::ostream& operator<<(std::ostream &out, const TStack &s){
        std::cout<<(s.end - s.begin)<<std::endl;
        for(int i = 0;i<(s.end - s.begin);++i){
            out<<s.begin[i]<<"\n";
        }
        return out;
    }
};



#endif //UNTITLED7_TSTACK_H
