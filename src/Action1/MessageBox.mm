#include "MessageBox.h"

#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

void message_box(const std::string& message) {
  NSAlert *alert = [[[NSAlert alloc] init] autorelease];
  [alert addButtonWithTitle:@"OK"];
  [alert setMessageText:@""];
  [alert setInformativeText:[NSString stringWithUTF8String:message.c_str()]];
  [alert runModal];
}

#endif
