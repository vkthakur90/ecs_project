#include <entity.h>
#include <vector3d.h>
#include <system.h>
#include <fstream>
#include <game_register.h>


int main(int argc, char** argv){
    EntityList el;
    
    for(int i = 0; i < 180; i++){
        auto entt = std::make_unique<Entity>();

        entt->pos = get_CylVector3D(1, 1*i, 0);
        entt->vel = get_CylVector3D(1, 1*i + 90, 0);

        el.push_back(std::move(entt));        
    }
    
    SystemList sl;
    
    sl.push_back(MoveSystem(0.1));
    
    auto game = get_GameRegister(el, sl);
    
    std::ofstream fout(argv[1]);
    
    for(int i = 0; i < 100; i++){
        fout << "Begin iteration " << i << '\n';
        game->displayState(fout);
        game->update();
        fout << "End iteration " << '\n';
    }
    
    return 0;
}