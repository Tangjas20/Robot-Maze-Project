#include "wall.h"

void wallSetPosition(struct Wall * wall, int x, int y, int width, int height) {
    wall->x = x;
    wall->y = y;
    wall->width = width;
    wall->height = height;
}

void wallUpdate(SDL_Renderer * renderer, struct Wall * wall){
    SDL_Rect rect = {wall->x, wall->y, wall->width, wall->height};
    SDL_SetRenderDrawColor(renderer, 255, 179, 102, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
}

//insert link at the first location
void insertFirstWall(struct Wall_collection ** head, int key, struct Wall * wall) {
   //create a link
   struct Wall_collection *link = (struct Wall_collection*) malloc(sizeof(struct Wall_collection));

   link->key = key;
   link->wall = *wall;

   //point it to old first node
   link->next = *head;

   //point first to new first node
   *head = link;
}

void insertAndSetFirstWall(struct Wall_collection ** head, int key, int x, int y, int width, int height){
   //create a link
   struct Wall *wall = (struct Wall*) malloc(sizeof(struct Wall));
   wallSetPosition(wall, x, y, width, height);
   insertFirstWall(head, key, wall);

}

void updateAllWalls(struct Wall_collection * head, SDL_Renderer * renderer) {
   struct Wall_collection *ptr = head;

   //start from the beginning
   while(ptr != NULL) {
      //printf("(%d)",ptr->key);
      wallUpdate(renderer, &ptr->wall);
      ptr = ptr->next;
   }

}

void horizontalwall(struct Wall_collection ** head,int length,int startx,int starty,int gorightanddown) {
        int i=0;
        if(gorightanddown==1){
        while ( i < length ) {
        insertAndSetFirstWall(head, 2,startx + i,starty + i,12, 12);
        i++;}}
        else{
        while ( i < length ) {
        insertAndSetFirstWall(head, 2,startx + i,starty - i,12, 12);
        i++;}}}
        
        
   // Draws a line based upon a given starting coordinate (x1, y1), and a ending coordinate (x2, y2)
// NOTE: positions are not exactly accurate (give 2-3 pixel) because of the size of sqaures drawn
int insertAndSetDiagonalWall(struct Wall_collection ** head, int key, int x1, int y1, int x2, int y2) {
    // x, y = the amount each sqaure will towards destination move each loop
    // loop = amount of iteration of the for
    double x, y, loop;

    // absolute value of the differences of the x values and y values
    double absX = sqrt((x1-x2)*(x1-x2));
    double absY = sqrt((y1-y2)*(y1-y2));

    // the biggest difference has the corresponding x/y value set to 2 (largest difference),
    // the remaining is set to a ratio that allows x/y to reach destination at same time
    if (absX >= absY){
       x = 2;
       loop = absX/2;
       y = absY/loop;
    }
    else {
       y = 2;
       loop = absY/2;
       x = absX/loop;
    }
   
    // Uncomment if you want to see these values manually
    //  printf("%d %d\n", x1, y1);
    //  printf("%d %d\n", x2, y2);
    //  printf("%f %f\n", absX, absY);
    //  printf("%f %f\n", x, y);

    // Makes sure the line is drawn in the correct direction based on each points
    // relative position to eachother
    int xNeg = 1;
    int yNeg = 1;

    if (x1 >= x2) {
       xNeg = -1;
    }
    if (y1 >= y2) {
       yNeg = -1;
    }

    // Draws each square until it reaches the given ending coordinate
    for (int i=0; i < loop; i++) {
       insertAndSetFirstWall(head, key + i, x1 + i*x*xNeg, y1 + i*y*yNeg, 8, 8);
    }

    // returns number of squares drawn so it is easy to find next key needed
    return (int)floor(loop + key);;
}
