#include <DxLib.h>

class IAmmo
{
public:
    IAmmo() :  position(VGet(0, 0, 0)), isActive(false) {} ;
    

    VECTOR GetPosition() const { return position; }
    void SetPosition(const VECTOR & pos) { position = pos; }

    bool GetIsActive() const { return isActive; }
    void SetIsActive(bool active) { isActive = active; }

     
    IAmmo(const VECTOR& pos) :position(pos) {};

    virtual void Draw()=0;

    virtual void Update(float AMMOVELOCITY) = 0;
    

protected:
   
    VECTOR position;
    bool isActive;
    float AMMOVELOCITY;
   
};
