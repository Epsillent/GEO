#include "entities/resources.hpp"

int Resources::get_resources(){
    return m_resources_count;
}

void Resources::resources_increase(int count){
    m_resources_count += count;
}