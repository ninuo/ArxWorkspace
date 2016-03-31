#pragma once
#ifndef ARXHELPER_API 
#ifdef ARXHELPER_MODULE
#define ARXHELPER_API __declspec(dllexport)
#else
#define ARXHELPER_API __declspec(dllimport)
#endif
#endif
