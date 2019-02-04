#include "MessageBox.h"

#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

int message_box::show(const std::string& message, const std::string& title) {
  NSAlert *alert = [[[NSAlert alloc] init] autorelease];
  [alert addButtonWithTitle:@"OK"];
  [alert setMessageText:[NSString stringWithUTF8String:title.c_str()]];
  [alert setInformativeText:[NSString stringWithUTF8String:message.c_str()]];
  [alert runModal];
  return 0;
}

#endif
