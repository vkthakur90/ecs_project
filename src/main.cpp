#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <vector3d.h>
#include <system.h>


int main(){
    EntityList el;
    
    for(int i = 0; i < 6; i++){
        auto entt = std::make_unique<Entity>();

        entt->pos = get_CylVector3D(1, 60*i, 0);

        el.push_back(std::move(entt));        
    }
    
    SystemList sl;
    
    sl.push_back(
        [](auto & x){
            move_system(x, 0.1);
        }
    );
    
    auto game = get_GameRegister(el, sl);
    
    game->displayState();
    game->update();
    game->displayState();
    
    return 0;
}