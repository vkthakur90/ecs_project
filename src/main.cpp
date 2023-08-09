#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <vector3d.h>
#include <system.h>

up_IfaceGameRegister init_game(){
    EntityList el;
    
    for(int i = 0; i < 6; i++){
        el.push_back({
            get_CylVector3D(1, 60 * i, 0),
            get_CylVector3D(1, 60 * i + 90, 0),
            nullptr
        });
    }
    
    SystemList sl = {
        MoveSystem(0.1)
    };
    
    return get_GameRegister(el, sl);
}

int main(){
    auto game = init_game();
    
    game->displayState();
    game->update();
    game->displayState();
    return 0;
}