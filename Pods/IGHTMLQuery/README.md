# What is it?

IGHTMLQuery is a lightweight XML/HTML parser for iOS, built on top of libxml. It is inspired by jQuery and nokogiri. Consider following snippets:

```objective-c
IGXMLDocument* node = [[IGXMLDocument alloc] initWithXMLString:catelogXml error:nil];
NSString* title = [[[node queryWithXPath:@"//cd/title"] firstObject] text];
[[node queryWithXPath:@"//title"] enumerateNodesUsingBlock:^(IGXMLNode *title, NSUInteger idx, BOOL *stop) {
    NSLog(@"title = %@", title.text);
}];

// quick manipulation
[[node queryWithXPath:@"//title"] appendWithXMLString:@"<message>Hi!</message>"];
```

## Features

- XPath support for document searching.
- jQuery style chainable syntax.
- XML traversal and manipulation.

## Installation

IGHTMLQuery is available through [CocoaPods](http://cocoapods.org/), to install it simply add the following line to your Podfile:

```ruby
pod "IGHTMLQuery"
```

Alternatively:

1. Add all the source files in ```Classes``` to your Xcoe project
2. In "Build Phases" > "Link Binary With Libraries, add ```libxml2```.
3. In "Build Setting", find "Header Search Paths" and add "$(SDK_DIR)/usr/include/libxml2"

## Usage

### Import header

For each files using IGHTMLQuery, import ```IGHTMLQuery.h```:

```
#import 'IGHTMLQuery.h'
```

### Create a document

Create a XML document:

```objective-c
IGXMLDocument* node = [[IGXMLDocument alloc] initWithXMLString:xml error:nil];
```

Create a HTML document:

```objective-c
IGHTMLDocument* node = [[IGHTMLDocument alloc] initWithHTMLString:html error:nil];
```

### Traversal

Use ```parent```, ```nextSibling```, ```previousSibling```, ```children``` and ```firstChild``` to traverse the document.

### Query using XPath

You can query the document or any node with ```queryWithXPath:``` method. It will always return a ```IGXMLNodeSet``` object, which is a set like object that you can chain query and operations.

```objective-c
IGXMLNodeSet* contents = [doc queryWithXPath:@"//div[@class='content']"];
[contents enumerateNodesUsingBlock:^(IGXMLNode* content, NSUInteger idx, BOOL *stop){
    NSLog(@"%@", content.xml);
}]

```

### Document Manipulation

You can change the document using methods in ```IGXMLNodeManipulation``` protocol.

```objective-c
@protocol IGXMLNodeManipulation <NSObject>

-(instancetype) appendWithNode:(IGXMLNode*)child;

-(instancetype) prependWithNode:(IGXMLNode*)child;

-(instancetype) addChildWithNode:(IGXMLNode*)child;

-(instancetype) addNextSiblingWithNode:(IGXMLNode*)child;

-(instancetype) addPreviousSiblingWithNode:(IGXMLNode*)child;

-(void) empty;

-(void) remove;

@end

```

## License

MIT License.
