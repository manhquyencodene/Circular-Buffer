#include "cbuffer.h"

void cb_init(cbuffer_t *cb, void *buf, uint32_t size) 
{
    if(size == 0 || size > CB_MAX_SIZE) 
    {
        cb->active = false;
        return;
    }
    cb->data = (uint8_t *)buf;
    cb->size = size;    
    cb->writer   = 0;
    cb->reader   = 0;
    cb->overflow = 0;
    cd->active   = true;
}

void cb_clear(cbuffer_t *cb) 
{
    cb ->writer   = 0;
    cb ->reader   = 0;
    cb ->overflow = 0;
}

uint32_t cb_read(cbuffer_t *cb, void *buf, uint32_t nbytes) 
{
    if(cb->active == false || buf == NULL || nbytes == 0) 
    {
        return 0;
    }
    uint8_t *test = (uint8_t *)buf;
    uint8_t read_count = 0 ; 
    while
    {
        if(cb_data_count < nbytes)
        {
            if(cb_data_count(cb) == 0) 
            {
                break;
            }
        }
        test[read_count] =cb->data[cb-reader];
        cb->reader = (cb->reader + 1) % cb->size;
        read_count++;       
    }
    return read_count;
}

uint32_t cb_write(cbuffer_t *cb, void *buf, uint32_t nbytes) 
{
    // Code
}

uint32_t cb_data_count(cbuffer_t *cb) 
{
    if(cb->writer >= cb->reader) 
    {
        return cb->writer - cb->reader;
    } 
    else 
    { 
        return (cb->size - cb->reader) + cb->writer;
    }
}

uint32_t cb_space_count(cbuffer_t *cb) 
{
   uint8_t cap = cb->size - 1 ; 
   return cap - cb_data_count(cb);
}
