<?xml version="1.0" encoding="UTF-16"?>
<!DOCTYPE DCARRIER SYSTEM "Mantis.DTD">

  <DCARRIER
    CarrierRevision="1"
    DTDRevision="16"
  >
    <TASKS
      Context="1"
      PlatformGUID="{00000000-0000-0000-0000-000000000000}"
    >    </TASKS>

    <PLATFORMS
      Context="1"
    >    </PLATFORMS>

    <REPOSITORIES
      Context="1"
      PlatformGUID="{00000000-0000-0000-0000-000000000000}"
    >    </REPOSITORIES>

    <GROUPS
      Context="1"
      PlatformGUID="{00000000-0000-0000-0000-000000000000}"
    >    </GROUPS>

    <COMPONENTS
      Context="0"
      PlatformGUID="{B784E719-C196-4DDB-B358-D9254426C38D}"
    >
      <COMPONENT
        ComponentVSGUID="{F192CA15-F830-4601-AB94-F927F786A965}"
        ComponentVIGUID="{8E9454E5-9F79-44C3-B6E2-478B3230ABB7}"
        Revision="620"
        RepositoryVSGUID="{8E0BE9ED-7649-47F3-810B-232D36C430B4}"
        Visibility="200"
        MultiInstance="False"
        Released="False"
        Editable="True"
        HTMLFinal="False"
        IsMacro="False"
        Opaque="False"
        Context="1"
        PlatformGUID="{B784E719-C196-4DDB-B358-D9254426C38D}"
      >
        <PROPERTIES
          Context="1"
          PlatformGUID="{00000000-0000-0000-0000-000000000000}"
        >        </PROPERTIES>

        <RESOURCES
          Context="1"
          PlatformGUID="{B784E719-C196-4DDB-B358-D9254426C38D}"
        >
          <RESOURCE
            Name="File(819):&quot;%12%&quot;,&quot;smclib.sys&quot;"
            ResTypeVSGUID="{E66B49F6-4A35-4246-87E8-5C1A468315B5}"
            BuildTypeMask="819"
            BuildOrder="1000"
            Localize="False"
            Disabled="False"
            Context="1"
            PlatformGUID="{B784E719-C196-4DDB-B358-D9254426C38D}"
          >
            <PROPERTIES
              Context="1"
              PlatformGUID="{00000000-0000-0000-0000-000000000000}"
            >
              <PROPERTY
                Name="DstPath"
                Format="String"
                Context="1"
                PlatformGUID="{00000000-0000-0000-0000-000000000000}"
              >%12%</PROPERTY>

              <PROPERTY
                Name="DstName"
                Format="String"
                Context="1"
                PlatformGUID="{00000000-0000-0000-0000-000000000000}"
              >smclib.sys</PROPERTY>

              <PROPERTY
                Name="NoExpand"
                Format="Boolean"
                Context="1"
                PlatformGUID="{00000000-0000-0000-0000-000000000000}"
              >False</PROPERTY>
            </PROPERTIES>

            <DISPLAYNAME>SMCLIB</DISPLAYNAME>

            <DESCRIPTION>Smart card reader driver library</DESCRIPTION>
          </RESOURCE>

          <RESOURCE
            Name="RawDep(819):&quot;File&quot;,&quot;ntoskrnl.exe&quot;"
            ResTypeVSGUID="{90D8E195-E710-4AF6-B667-B1805FFC9B8F}"
            BuildTypeMask="819"
            BuildOrder="1000"
            Localize="False"
            Disabled="False"
            Context="1"
            PlatformGUID="{B784E719-C196-4DDB-B358-D9254426C38D}"
          >
            <PROPERTIES
              Context="1"
              PlatformGUID="{00000000-0000-0000-0000-000000000000}"
            >
              <PROPERTY
                Name="RawType"
                Format="String"
                Context="1"
                PlatformGUID="{00000000-0000-0000-0000-000000000000}"
              >File</PROPERTY>

              <PROPERTY
                Name="Value"
                Format="String"
                Context="1"
                PlatformGUID="{00000000-0000-0000-0000-000000000000}"
              >ntoskrnl.exe</PROPERTY>
            </PROPERTIES>
          </RESOURCE>

          <RESOURCE
            Name="RawDep(819):&quot;File&quot;,&quot;HAL.dll&quot;"
            ResTypeVSGUID="{90D8E195-E710-4AF6-B667-B1805FFC9B8F}"
            BuildTypeMask="819"
            BuildOrder="1000"
            Localize="False"
            Disabled="False"
            Context="1"
            PlatformGUID="{B784E719-C196-4DDB-B358-D9254426C38D}"
          >
            <PROPERTIES
              Context="1"
              PlatformGUID="{00000000-0000-0000-0000-000000000000}"
            >
              <PROPERTY
                Name="RawType"
                Format="String"
                Context="1"
                PlatformGUID="{00000000-0000-0000-0000-000000000000}"
              >File</PROPERTY>

              <PROPERTY
                Name="Value"
                Format="String"
                Context="1"
                PlatformGUID="{00000000-0000-0000-0000-000000000000}"
              >HAL.dll</PROPERTY>
            </PROPERTIES>
          </RESOURCE>
        </RESOURCES>

        <GROUPMEMBERS
        >
          <GROUPMEMBER
            GroupVSGUID="{E01B4103-3883-4FE8-992F-10566E7B796C}"
          ></GROUPMEMBER>

          <GROUPMEMBER
            GroupVSGUID="{655158DE-E43C-4C05-B1E4-C5F8C867155E}"
          ></GROUPMEMBER>
        </GROUPMEMBERS>

        <DEPENDENCIES
          Context="1"
          PlatformGUID="{B784E719-C196-4DDB-B358-D9254426C38D}"
        >
          <DEPENDENCY
            Class="Include"
            Type="All"
            DependOnGUID="{D97EEF9A-29DA-4F7D-A747-69FCC3A1E994}"
            MinRevision="0"
            Disabled="False"
            Context="1"
            PlatformGUID="{B784E719-C196-4DDB-B358-D9254426C38D}"
          >
            <PROPERTIES
              Context="1"
              PlatformGUID="{00000000-0000-0000-0000-000000000000}"
            >            </PROPERTIES>
          </DEPENDENCY>
        </DEPENDENCIES>

        <DISPLAYNAME>Smart Card Reader Driver Library</DISPLAYNAME>

        <VERSION>1.0</VERSION>

        <DESCRIPTION>Smart Card Reader Driver Library</DESCRIPTION>

        <COPYRIGHT>2000 Microsoft Corp.</COPYRIGHT>

        <VENDOR>Microsoft Corp.</VENDOR>

        <OWNERS>randyau</OWNERS>

        <AUTHORS>randyau</AUTHORS>

        <DATECREATED>7/13/2001</DATECREATED>

        <DATEREVISED>8/19/2001 6:38:50 PM</DATEREVISED>
      </COMPONENT>
    </COMPONENTS>

    <RESTYPES
      Context="1"
      PlatformGUID="{00000000-0000-0000-0000-000000000000}"
    >    </RESTYPES>
  </DCARRIER>
