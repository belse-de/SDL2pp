//
// Created by belse on 15.03.18.
//

#include "catch.hpp"

#include "../src/Base.hpp"
using namespace Widget;

TEST_CASE( "Base class", "[base][widget][lib]" ) {

    SECTION("registering parents and children"){
        std::vector<std::shared_ptr<Base>> cache;
        for(int i=0; i<4; ++i){
            cache.push_back(std::make_shared<Base>());
            CHECK_FALSE(cache[i]->hasParent());
            CHECK_FALSE(cache[i]->hasChildren());

            if(i>=1){
                cache[i]->registerParent(cache[i-1]);
                cache[i-1]->registerChild(cache[i]);
                CHECK(cache[i]->hasParent());
                CHECK(cache[i-1]->hasChildren());
            }
        }
    }

    SECTION("absolute position calculations"){
        std::vector<std::shared_ptr<Base>> cache;
        for(int i=0; i<4; ++i){
            cache.push_back(std::make_shared<Base>());
            cache[i]->_area = Rect{1,1,2,2};
            cache[i]->_hitbox = Rect{1,1,1,1};

            CHECK_FALSE(cache[i]->hasParent());
            CHECK_FALSE(cache[i]->hasChildren());

            if(i>=1){
                cache[i]->registerParent(cache[i-1]);
                cache[i-1]->registerChild(cache[i]);
                CHECK(cache[i]->hasParent());
                CHECK(cache[i-1]->hasChildren());
            }
            cache[i]->updateAbsolute();
            CHECK(cache[i]->_areaAbsolute == Rect{i+1,i+1,2,2});
            CHECK(cache[i]->_hitboxAbsolute == Rect{i+2,i+2,1,1});
        }
    }
}

