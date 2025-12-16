#pragma once

void m_plug_init(void* s, const char* file_path);
void reloadDLL();
void m_plug_update(void* s);
void m_plug_shutdown(void* s);
void m_post_reload(void* s);
void m_pre_reload(void* s);