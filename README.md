## 使用：

```c

pod 'UFKit'
 
   - (void)viewDidLoad {
    [super viewDidLoad];

    __block UFFormView *formView = [UFFormView makeFormView:^(UFFormViewMaker * _Nonnull make) {
        make
        .rowHeight(50)
        .addSection([UFSection makeSection:^(UFSectionMaker * _Nonnull make) {
            make
            .titleStyle([UFRowTitleStyle makeTitleStyle:^(UFRowTitleStyleMaker * _Nonnull make) {
                make
                .font([UIFont systemFontOfSize:15])
                .textAlignment(NSTextAlignmentLeft);
            }])
            .valueStyle([UFTextStyle makeTextStyle:^(UFRowTextStyleMaker * _Nonnull make) {
                make
                .font([UIFont systemFontOfSize:15])
                .color([UIColor darkTextColor])
                .textAlignment(NSTextAlignmentRight);
            }])
            .addRow([UFAvatarRow makeAvatarRow:^(UFAvatarRowMaker * _Nonnull make) {
                make
                .cornerRadius(30)
                .avatarImage([UIImage imageNamed:@"touxiang"])
                .avatarDidSelected(^(__kindof UFAvatarRow * _Nonnull row, UIImageView * _Nonnull avatarView) {
                    NSLog(@"你点击了头像");
                })
                .title(@"头像")
                .value(@"http://img0.imgtn.bdimg.com/it/u=2572957358,1108684168&fm=26&gp=0.jpg")
                .name(@"avatar")
                .accessoryType(UFRowAccessorySpace);
            }])
            .addRow([UFTextFieldRow makeTextFieldRow:^(UFTextFieldRowMaker * _Nonnull make) {
                make
                .limitType(UFInputLimitTypeIdCard)
                .title(@"姓名")
                .value(@"")
                .name(@"name")
                .accessoryType(UFRowAccessorySpace);
            }])
            .addRow([UFRadioGroupRow makeRadioGroupRow:^(UFRadioGroupRowMaker * _Nonnull make) {
                make
                .itemArray(@[@"男",@"女"])
                .title(@"性别")
                .value(@"男")
                .name(@"gender")
                .accessoryType(UFRowAccessorySpace);
            }])
            .addRow([UFTextFieldRow makeTextFieldRow:^(UFTextFieldRowMaker * _Nonnull make) {
                make
                .limitType(UFInputLimitTypeMobile)
                .title(@"联系方式")
                .name(@"mobile")
                .accessoryType(UFRowAccessorySpace);
            }])
            .addRow([UFMobileCodeRow makeCodeRow:^(UFCodeRowMaker * _Nonnull make) {
                make
                .codeStyle([UFMobileCodeStyle makeMobileCodeStyle:^(UFMobileCodeStyleMaker * _Nonnull make) {
                    
                }])
                .codeDidClicked(^(__kindof UFMobileCodeRow * _Nonnull row, UIButton * _Nonnull button) {
                    NSLog(@"点了了获取验证码");
                })
                .maxLength(4)
                .limitType(UFInputLimitTypeNumbers)
                .title(@"验证码")
                .name(@"code")
                .accessoryType(UFRowAccessorySpace);
            }])
            .addRow([UFPickerViewRow makePickerViewRow:^(UFPickerViewRowMaker * _Nonnull make) {
                make
                .itemArray(@[@"iOS",@"macOS",@"swift",@"iPhone",@"iPad",@"iPod"])
                .title(@"技能")
                .value(@"iOS")
                .name(@"skills")
                .accessoryType(UFRowAccessoryDisclosureIndicator);
            }])
            .addRow([UFMultiplePickerViewRow makeMultiplePickerViewRow:^(UFMultiplePickerViewRowMaker * _Nonnull make) {
                make
                .itemArray(@[@"看电影",@"旅游",@"看书",@"打游戏",@"篮球",@"足球",@"其他"])
                .title(@"爱好")
                .value(@"打游戏,其他")
                .name(@"hobby")
                .accessoryType(UFRowAccessoryDisclosureIndicator);
            }])
            .addRow([UFDatePickerRow makeDatePickerRow:^(UFDatePickerRowMaker * _Nonnull make) {
                make
                .datePickerMode(UIDatePickerModeDate)
                .dateFormat(@"yyyy-MM-dd")
                .title(@"生日")
                .name(@"birthday")
                .accessoryType(UFRowAccessoryDisclosureIndicator);
            }])
            .addRow([UFAreaPickerRow makeAreaPickerRow:^(UFAreaPickerRowMaker * _Nonnull make) {
                make
                .areaSeparator(@",")
                .title(@"地址")
                .name(@"address")
                .accessoryType(UFRowAccessoryDisclosureIndicator);
            }])
            .addRow([UFSwitchRow makeSwitchRow:^(UFSwitchRowMaker * _Nonnull make) {
                make
                .tintColor([UIColor redColor])
                .title(@"免打扰")
                .value(SWITCH_ON)
                .name(@"allow")
                .accessoryType(UFRowAccessorySpace)
                .valueDidChanged(^(__kindof UFRow * _Nonnull row, __kindof NSString * _Nonnull value) {
                    if ([row.value boolValue]) {
                        NSLog(@"开");
                    } else {
                        NSLog(@"关");
                    }
                });
            }])
            .addRow([UFPlateNumberRow makePlateNumberRow:^(UFPlateNumberRowMaker * _Nonnull make) {
                make
                .title(@"车牌号")
                .value(@"鲁A12345")
                .titleStyle([UFRowTitleStyle makeTitleStyle:^(UFRowTitleStyleMaker * _Nonnull make) {
                    make
                    .width([UIScreen mainScreen].bounds.size.width - 175)
                    .textAlignment(NSTextAlignmentLeft);
                }])
                .name(@"plate")
                .accessoryType(UFRowAccessorySpace);
            }])
            .addRow([UFTextViewRow makeTextViewRow:^(UFTextViewRowMaker * _Nonnull make) {
                make
                .maxLength(0)
                .title(@"个人简介")
                .value(@"苹果公司是美国一家高科技公司。由史蒂夫·乔布斯、斯蒂夫·沃兹尼亚克和罗·韦恩等人于1976年4月1日创立，总部位于加利福尼亚州的库比蒂诺")
                .name(@"introduction")
                .accessoryType(UFRowAccessorySpace);
            }]);
        }])
        .addSubmitButton([UFActionButton makeActionButton:^(UFActionButtonMaker * _Nonnull make) {
            make
            .titleForState(@"提交", UIControlStateNormal)
            .titleColorForState([UIColor whiteColor], UIControlStateNormal)
            .cornerRadius(17)
            .backgroundColor([UIColor redColor])
            .actionButtonClick(^(UFActionButton * _Nonnull button) {
                NSLog(@"提交的信息：\n%@",[formView toDictionary]);
            });
        }])
        .addToSuperView(self.view);
    }];

    [formView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.mas_equalTo(self.view);
    }];
}

 
```


## 依赖：

'Masonry', '~> 1.1.0'  

'SDWebImage', '~> 5.0.6'  

'IQKeyboardManager', '~> 6.3.0'



## 效果：
![](https://user-gold-cdn.xitu.io/2019/8/27/16cd2037fb3104e4?w=1242&h=2688&f=png&s=283943)

![](https://img-blog.csdnimg.cn/20190726140738297.png)

