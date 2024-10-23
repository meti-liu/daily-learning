



bool TestAndSet(bool *lock) 
{
    bool oldValue = *lock;  // 读取 lock 的当前值
    *lock = true;           // 设置 lock 为 true（加锁）
    return oldValue;        // 返回原来的值
}





bool lock = false;  // 初始化锁为未锁定状态

void acquire_lock() 
{
    while (TestAndSet(&lock));
        // 自旋等待直到锁被释放

}

void release_lock() 
{
    lock = false;  // 释放锁
}
