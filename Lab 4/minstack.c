
typedef struct{
    int array[30000];
    int min[30000];
    int top1;
    int top2;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));

    obj->top1=-1;
    obj->top2=-1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->array[++obj->top1]=val;
    if(obj->top2==-1){
        obj->min[++obj->top2]=val;
        return;
    }
    int mintop=obj->min[obj->top2];
    if(mintop>val){0
        obj->min[++obj->top2]=val;
        return;
    }
    else{
        obj->min[++obj->top2]=mintop;
    }
}

void minStackPop(MinStack* obj) {
    obj->top1--;
    obj->top2--;
}

int minStackTop(MinStack* obj) {
    return obj->array[obj->top1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top2];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
