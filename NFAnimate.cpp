#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"

emp::web::Document doc{"target"};

class NFAnimator : public emp::web::Animate {
    emp::web::Canvas canvas{1000, 1000, "canvas"};

    public:
        NFAnimator() {
            doc << canvas;

            // creates 10 by 10 grid of "squares"
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    int x = i * 30;
                    int y = j * 30;
                    canvas.Rect(x, y, 30, 30, "black", "white");
                    canvas.CenterText(x + 15, y + 15, std::to_string(i)+","+std::to_string(j), "yellow", "yellow");
                }
            }
        }

        void FindNeighbors(int x, int y){
            canvas.Rect(x * 30, y * 30, 30, 30, "yellow", "white");
            // Need to find 8 neighbors around cell
            
        }
};

NFAnimator animator;

int main() {
    animator.Step();
    animator.FindNeighbors(5, 5);
}